#include "Functions.h"
#include "Player.h"
#include "sqlite3.h"
using namespace std;

int Functions::GetDouble(long i) {
    switch (i) {
        case 0: return 0;
        case 1: return 2;
        case 2: return 4;
        case 3: return 6;
        case 4: return 8;
        case 5: return 1;
        case 6: return 3;
        case 7: return 5;
        case 8: return 7;
        case 9: return 9;
        default: return 0;
    }
}

bool Functions:: IsValidIsraeliID(const std::string& israeliID) {
    if (israeliID.length() != 9)
        return false;

    long sum = 0;

    for (int i = 0; i < israeliID.length(); i++) {
        int digit = israeliID[israeliID.length() - 1 - i] - '0';
        sum += (i % 2 != 0) ? GetDouble(digit) : digit;
    }

    return sum % 10 == 0;
}

bool Functions::checkLogin_P(sqlite3* db, const string& id, const string& password) {
    sqlite3_stmt *stmt;
    string sql = "SELECT * FROM [Player_Accounts] WHERE ID='" + id + "' AND Password='" + password + "'";
    int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL);

    if (rc != SQLITE_OK) {
        cerr << "Failed to execute query: " << sql << "\n";
        cerr << "Error: " << sqlite3_errmsg(db) << "\n";
        return false;
    }

    bool loginSuccess = sqlite3_step(stmt) == SQLITE_ROW;
    sqlite3_finalize(stmt);
    return loginSuccess;
}

bool Functions:: checkLogin_FM(sqlite3* db, const string& id, const string& password) {
    sqlite3_stmt *stmt;
    string sql = "SELECT * FROM [Field_Manager_Accounts] WHERE ID='" + id + "' AND Password='" + password + "'";
    int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL);

    if (rc != SQLITE_OK) {
        cerr << "Failed to execute query: " << sql << "\n";
        cerr << "Error: " << sqlite3_errmsg(db) << "\n";
        return false;
    }

    bool loginSuccess = sqlite3_step(stmt) == SQLITE_ROW;
    sqlite3_finalize(stmt);
    return loginSuccess;
}


//Insert User data to DB
int Functions::P_insert_to_DB(Player &fm) {
    // Insert player account data
    const char* insert_sql = "INSERT INTO [Player_Accounts] (Name, ID, Phone_number, Gender, Address, Birthday, Password,Class_data) VALUES (?,?,?,?,?,?,?,?)";
    sqlite3* db;

    int rc = sqlite3_open("Test player data DB.db", &db);
    if (rc) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return rc;
    }


    const char* sql = "INSERT INTO [Player_Accounts] (Name, ID, Phone_number, Gender, Address, Birthday, Password,Class_data) VALUES (?, ?, ?, ?, ?, ?, ?,?)";
    sqlite3_stmt* stmt;
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Error preparing statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return rc;
    }
    const char* gender = fm.Get_gender() == 'M' ? "Male" : "Female";


    json data_json;
    fm.to_json(data_json);
    std::string json_str =data_json.dump();

    sqlite3_bind_text(stmt, 1, fm.Get_Name().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2, fm.Get_id());
    sqlite3_bind_int(stmt, 3, fm.Get_phone_number());
    sqlite3_bind_text(stmt, 4, gender, 1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 5, fm.Get_Address().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 6, fm.date_to_string().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 7, fm.get_password().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 8, json_str.c_str(), -1, SQLITE_STATIC);

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        std::cerr << "Error inserting data: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return rc;
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return SQLITE_OK;
}
int Functions:: FM_insert_to_DB(Field_manager &fm){
    sqlite3* db;

    int rc = sqlite3_open("Test player data DB.db", &db);
    if (rc) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return rc;
    }


    const char* sql = "INSERT INTO [Field_Manager_Accounts] (Name, ID, Phone_number, Gender, Address, Birthday, Password,Class_data) VALUES (?, ?, ?, ?, ?, ?, ?,?)";
    sqlite3_stmt* stmt;
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Error preparing statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return rc;
    }
    const char* gender = fm.Get_gender() == 'M' ? "Male" : "Female";


    json data_json;
    fm.to_json(data_json);

    sqlite3_bind_text(stmt, 1, fm.Get_Name().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2, fm.Get_id());
    sqlite3_bind_int(stmt, 3, fm.Get_phone_number());
    sqlite3_bind_text(stmt, 4, gender, 1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 5, fm.Get_Address().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 6, fm.date_to_string().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 7, fm.get_password().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 8, data_json.dump().c_str(), -1, SQLITE_STATIC);

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        std::cerr << "Error inserting data: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return rc;
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return SQLITE_OK;
}











