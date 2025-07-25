#include <gtest/gtest.h>
#include "avatar.h"


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

class MovgameTest : public ::testing::Test {
protected:
    movgame avatar;

    sf::RenderWindow window{sf::VideoMode(800, 600), "Test Window"};

    void SetUp() override {
        avatar.setPos(928.0f, 600.0f);
    }

    float getX() { return avatar.getPosX(); }
    float getY() { return avatar.getPosY(); }
};

// Test: la posizione iniziale è quella attesa
TEST_F(MovgameTest, InitialPosition) {
    EXPECT_FLOAT_EQ(avatar.getPosX(), 928.0f);
    EXPECT_FLOAT_EQ(avatar.getPosY(), 600.0f);
}

// Test dei limiti di movimento verso l'alto (up_g)
// Esempio: se posy_g < cy3 e posx_g < cx1, posy_g deve essere clonecy3
TEST_F(MovgameTest, LimitUpMovement) {
    avatar.setPos(860.0f, 570.0f);  // posx_g < cx1 (872), posy_g < cy3 (585)
    avatar.up_g(window,true); 
    EXPECT_FLOAT_EQ(avatar.getPosY(), 585.0f);  // clonecy3
}

// Test movimento verso il basso senza limiti attivi
TEST_F(MovgameTest, MoveDownBasic) {
    float oldY = getY();
    avatar.down_g(window, true);
    EXPECT_FLOAT_EQ(avatar.getPosY(), oldY + 1.0f);
}

// Test limite con cy2 (posy_g > cy2)
TEST_F(MovgameTest, LimitDownMovement) {
    avatar.setPos(900.0f, 780.0f);  // posy_g > cy2 (772)
    avatar.down_g(window,true);
    EXPECT_FLOAT_EQ(avatar.getPosY(), 772.0f);  // cy2
}

// Test movimento verso sinistra (left_g)
TEST_F(MovgameTest, MoveLeftBasic) {
    float oldX = getX();
    avatar.left_g(window,true);
    EXPECT_FLOAT_EQ(avatar.getPosX(), oldX - 1.0f);
}

// Test movimento verso destra (right_g)
TEST_F(MovgameTest, MoveRightBasic) {
    float oldX = getX();
    avatar.right_g(window,true);
    EXPECT_FLOAT_EQ(avatar.getPosX(), oldX + 1.0f);
}
