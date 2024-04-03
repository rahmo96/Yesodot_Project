//
// Created by חי כרמי on 20/02/2024.
//

#include "User.h"

User::User(const User &user) {

    this->name = user.name;
    this->id = user.id;
    this->phone_number = user.phone_number;
    this->Address = user.Address;
    this->gender = user.gender;
    this->b_day = user.b_day;
    //
    this->passowrd = user.passowrd;
}

User::User(string name, long id, string address, long phone_num, char gender, Date b_day, string password) {
    this->name = name;
    this->id = id;
    this->phone_number = phone_num;
    this->Address = address;
    this->gender = gender;
    this->b_day = b_day;
    this->passowrd = password;
}

void User::print() {
    cout << "Name:" << this->name << endl;
    cout << "ID:" << id << endl;
    cout << "Address:" << Address << endl;
    cout << "Phone number: " <<"0"<< phone_number << endl;
    cout << "Gender:";
    if (gender == 'M'||gender == 'm')
        cout << "Male" << endl;
    else
        cout << "Female" << endl;
    cout << "the birth day is:" << date_to_string() << endl;
    }

string User::date_to_string() {
        if (b_day.check_valid_date())
            return to_string(b_day.get_Day()) + "-" + to_string(b_day.get_Month()) + "-" + to_string(b_day.get_Year());
        else
            return "";
}



void User::to_json(nlohmann::json &j) {


    j = {
            {"Name", name},
            {"id", id},
            {"address", Address},
            {"phone_num", phone_number},
            {"gender", to_string(gender)},
            {"b_day", date_to_string()},
            {"password", passowrd}
    };

}

void User::from_json(const nlohmann::json &j) {

    name = j["Name"];
    id = j["id"];
    Address = j["address"];
    phone_number = j["phone_num"];
    passowrd = j["password"];

}

nlohmann::json User::P_from_DB(long id) {
    sqlite3 *db;
    sqlite3_stmt *stmt;
    nlohmann::json j;
    sqlite3_open("Test player data DB.db", &db);

    std::string query = "SELECT Class_data FROM [Player_Accounts] WHERE id =" + std::to_string(id);
    const char* sql = query.c_str();

    sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        j = nlohmann::json::parse((char *) sqlite3_column_text(stmt, 0));
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return j;

}
nlohmann::json User::FM_from_DB(long id) {
    sqlite3 *db;
    sqlite3_stmt *stmt = nullptr;
    nlohmann::json j;

    // Open the database
    if (sqlite3_open("Test player data DB.db", &db) != SQLITE_OK) {
        std::cerr << "Error opening database" << std::endl;
        return j;
    }

    // Prepare the SQL query
    std::string query = "SELECT Class_data FROM [Field_Manager_Accounts] WHERE id = ?";
    if (sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Error preparing statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return j;
    }

    // Bind the id parameter
    if (sqlite3_bind_int(stmt, 1, id) != SQLITE_OK) {
        std::cerr << "Error binding parameter: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return j;
    }

    // Execute the query
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        const char* json_text = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        try {
            j = nlohmann::json::parse(json_text);
            // Check if JSON object is null
            if (j.is_null()) {
                std::cerr << "Error: JSON object is null" << std::endl;
            }
        } catch (const nlohmann::json::parse_error& e) {
            std::cerr << "Error parsing JSON: " << e.what() << std::endl;
        }
    }

    // Finalize the statement and close the database connection
    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return j;
}

bool User::FM_update_to_DB() {
    // Serialize the updated Player object to a JSON string
    nlohmann::json player_data;
    this->to_json(player_data);

    sqlite3 *db;
    if (sqlite3_open("Test player data DB.db", &db) != SQLITE_OK) {
        std::cerr << "Error opening database" << std::endl;
        return false;
    }

    // Update the Class_data column in the database with the updated JSON string
    std::string update_query =
            "UPDATE [Field_Manager_Accounts] SET [Class_data] = '" + player_data.dump() + "' WHERE id = " +
            std::to_string(this->Get_id());
    const char *sql = update_query.c_str();
    if (sqlite3_exec(db, sql, nullptr, nullptr, nullptr) != SQLITE_OK) {
        std::cerr << "Error updating database" << std::endl;
        sqlite3_close(db);
        return false;
    }

    sqlite3_close(db);
    return true;
}
bool User::P_update_to_DB() {
    // Serialize the updated Player object to a JSON string
    nlohmann::json player_data;
    this->to_json(player_data);

    sqlite3 *db;
    if (sqlite3_open("Test player data DB.db", &db) != SQLITE_OK) {
        std::cerr << "Error opening database" << std::endl;
        return false;
    }

    // Update the Class_data column in the database with the updated JSON string
    std::string update_query =
            "UPDATE [Field_Manager_Accounts] SET [Class_data] = '" + player_data.dump() + "' WHERE id = " +
            std::to_string(this->Get_id());
    const char *sql = update_query.c_str();
    if (sqlite3_exec(db, sql, nullptr, nullptr, nullptr) != SQLITE_OK) {
        std::cerr << "Error updating database" << std::endl;
        sqlite3_close(db);
        return false;
    }

    sqlite3_close(db);
    return true;
}



void User::P_send_name_to_DB(string name) {
    sqlite3 *db;
    sqlite3_stmt *stmt;
    json j;
    this->to_json(j);
    sqlite3_open("Test player data DB.db", &db);
    sqlite3_prepare_v2(db, "UPDATE [Player_Accounts] SET Name = ? WHERE id = ?", -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2, this->id); // Assuming id is a member variable of User
    sqlite3_step(stmt);
    sqlite3_prepare_v2(db, "UPDATE [Player_Accounts] SET Class_data = ? WHERE id = ?", -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, j.dump().c_str(), -1, SQLITE_STATIC);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

void User::P_send_address_to_DB(string address) {
    sqlite3 *db;
    sqlite3_stmt *stmt;
    sqlite3_open("Test player data DB.db", &db);
    sqlite3_prepare_v2(db, "UPDATE [Player_Accounts] SET Address = ? WHERE id = ?", -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, address.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2, this->id); // Assuming id is a member variable of User
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

void User::P_send_phone_number_to_DB(long phone_num) {
    sqlite3 *db;
    sqlite3_stmt *stmt;
    sqlite3_open("Test player data DB.db", &db);
    sqlite3_prepare_v2(db, "UPDATE [Player_Accounts] SET Phone_number = ? WHERE id = ?", -1, &stmt, nullptr);
    sqlite3_bind_int64(stmt, 1, phone_num);
    sqlite3_bind_int(stmt, 2, this->id); // Assuming id is a member variable of User
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

void User::P_send_password_to_DB(string password) {
    sqlite3 *db;
    sqlite3_stmt *stmt;
    sqlite3_open("Test player data DB.db", &db);
    sqlite3_prepare_v2(db, "UPDATE [Player_Accounts] SET Password = ? WHERE id = ?", -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, password.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2, this->id); // Assuming id is a member variable of User
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

void User::FM_send_name_to_DB(string name) {
    sqlite3 *db;
    sqlite3_stmt *stmt;
    json j;
    this->to_json(j);
    sqlite3_open("Test player data DB.db", &db);
    sqlite3_prepare_v2(db, "UPDATE [Field_Manager_Accounts] SET Name = ? WHERE id = ?", -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2, this->id); // Assuming id is a member variable of User
    sqlite3_step(stmt);
    sqlite3_prepare_v2(db, "UPDATE [Field_Manager_Accounts] SET Class_data = ? WHERE id = ?", -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, j.dump().c_str(), -1, SQLITE_STATIC);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

void User::FM_send_address_to_DB(string address) {
    sqlite3 *db;
    sqlite3_stmt *stmt;
    sqlite3_open("Test player data DB.db", &db);
    sqlite3_prepare_v2(db, "UPDATE [Field_Manager_Accounts] SET Address = ? WHERE id = ?", -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, address.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2, this->id); // Assuming id is a member variable of User
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

void User::FM_send_phone_number_to_DB(long phone_num) {
    sqlite3 *db;
    sqlite3_stmt *stmt;
    sqlite3_open("Test player data DB.db", &db);
    sqlite3_prepare_v2(db, "UPDATE [Field_Manager_Accounts] SET Phone_number = ? WHERE id = ?", -1, &stmt, nullptr);
    sqlite3_bind_int64(stmt, 1, phone_num);
    sqlite3_bind_int(stmt, 2, this->id); // Assuming id is a member variable of User
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

void User::FM_send_password_to_DB(string password) {
    sqlite3 *db;
    sqlite3_stmt *stmt;
    sqlite3_open("Test player data DB.db", &db);
    sqlite3_prepare_v2(db, "UPDATE [Field_Manager_Accounts] SET Password = ? WHERE id = ?", -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, password.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2, this->id); // Assuming id is a member variable of User
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}



