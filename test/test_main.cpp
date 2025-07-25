#include <gtest/gtest.h>
#include "avatar.h"


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

class MovgameTest : public ::testing::Test {
protected:
    movgame avatar;

   
    void setPosition(float x, float y) {
        // ipotizziamo di poter accedere direttamente 
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
    avatar.up_g(*(new sf::RenderWindow())); 
    EXPECT_FLOAT_EQ(avatar.getPosY(), 585.0f);  // clonecy3
}

