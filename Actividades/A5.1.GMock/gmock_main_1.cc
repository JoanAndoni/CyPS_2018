#include <iostream>
#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace std;

using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;

class DataBaseConnect
{
    public:
        virtual bool login(string username, string password) { return true; }
        virtual bool logout(string username) { return true; }
        virtual int fetchRecrod() { return -1; }
};

class MyDatabase
{
    DataBaseConnect & dbConnect;
    public:
        MyDatabase(DataBaseConnect &_dbC) : dbConnect(_dbC) {}
        int Init(string uname, string passwd)
        {
            if(dbConnect.login(uname, passwd) != true)
            {
                cout << "Failed to connect :(" << endl;
                return -1;
            }
            else
            {
                cout << "Succesful connection >>>>>>>>" << endl;
                return 1;
            }
        }

        int Out(string uname)
        {
          if(dbConnect.logout(uname) != true)
          {
            cout << "Failed to logout :(" << endl;
            return -1;
          }
          else
          {
            cout << "Succesful logout >>>>>>>>" << endl;
            return 1;
          }
        }

        int check()
        {
          if(dbConnect.fetchRecrod() != -1)
          {
            cout << "Failed to show :(" << endl;
          }
          else
          {
            cout << "This is your fetchRecord >>>>>>>>" << endl;
          }
        }
};

class MockDB : public DataBaseConnect
{
    public:
        MOCK_METHOD0(fetchRecrod, int());
        MOCK_METHOD1(logout, bool(string uname));
        MOCK_METHOD2(login, bool(string uname, string passwd));
};

TEST(MyDBTest, LoginTest)
{
    // Arrange
    MockDB mdb;
    MyDatabase db(mdb);
    EXPECT_CALL(mdb, login("usuario", "password"))
        .Times(1)
        .WillOnce(Return(true));

    EXPECT_CALL(mdb, logout("usuario"))
        .Times(1)
        .WillOnce(Return(true));

    EXPECT_CALL(mdb, fetchRecrod())
        .Times(1)
        .WillOnce(Return(-1));

    // Act
    int retValue = db.Init("usuario", "password");
    int retValue2 = db.Out("usuario");
    db.check();
    // Assert
    EXPECT_EQ(1, retValue);
    EXPECT_EQ(1, retValue2);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
