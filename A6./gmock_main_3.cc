#include <iostream>
#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace std;
using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;
using ::testing::InSequence;

class Tortuga {
public:
  virtual ~Tortuga() {}
  virtual void PenUp() {}
  virtual void PenDown() {}
  virtual void GetX() {}
  virtual void GetY() {}
  virtual int Forward(int distancia) { return distancia; }
  virtual int Turn(int grados) { return grados; }
  virtual int GoTo(int x, int y) { return x*y; }
};

class MockTortuga : public Tortuga {
 public:
   MOCK_METHOD0(PenUp, void());
   MOCK_METHOD0(PenDown, void());
   MOCK_METHOD0(GetX, void());
   MOCK_METHOD0(GetY, void());
   MOCK_METHOD1(Forward, int(int distancia));
   MOCK_METHOD1(Turn, int(int grados));
   MOCK_METHOD2(GoTo, int(int x, int y));
};

class Pintor {
  Tortuga & t;
public:
  Pintor(Tortuga & _t) : t(_t) { }
  void pinta() {
    t.GetX();
    t.GetY();
    t.PenDown();
    t.Turn(25);
    t.GoTo(2,3);
    t.Forward(10);
    t.PenUp();
  }
};

TEST(PruebaDibujo, DibujaAlgo) {
  // Arrange
  MockTortuga turtle;
  Pintor t(turtle);
  {
  InSequence algo;
    EXPECT_CALL(turtle, GetX()).Times(1);
    EXPECT_CALL(turtle, GetY()).Times(1);
    EXPECT_CALL(turtle, PenDown()).Times(1);
    EXPECT_CALL(turtle, Turn(25)).Times(1);
    EXPECT_CALL(turtle, GoTo(2,3)).Times(1);
    EXPECT_CALL(turtle, Forward(10)).Times(1);
    //EXPECT_CALL(turtle, GetX()).Times(1);
    //EXPECT_CALL(turtle, GetY()).Times(1);
    EXPECT_CALL(turtle, PenUp()).Times(1);
  }
  // Act
  t.pinta();
	// Assert

  //EXPECT_EQ(1, retValue);
	//
}


int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
