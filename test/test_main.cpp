#include <gtest/gtest.h>
#include "avatar.h"

// Inizializzazione Google Test
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

class MovgameTest : public ::testing::Test {
protected:
    Mappa mappa;              // Oggetto mappa necessario per Personaggio
    Personaggio avatar{928.0f, 600.0f, mappa};  // Inizializzazione con posizione e mappa

    void SetUp() override {
        avatar.setPos(928.0f, 600.0f);
    }

    float GetX() { return avatar.getX(); }
    float GetY() { return avatar.getY(); }
};

// Test: la posizione iniziale è quella attesa
TEST_F(MovgameTest, InitialPosition) {
    EXPECT_FLOAT_EQ(avatar.getX(), 928.0f);
    EXPECT_FLOAT_EQ(avatar.getY(), 600.0f);
}

// Esempio per movimento verso l'alto
TEST_F(MovgameTest, MoveUpBasic) {
    avatar.setPos(100.0f, 100.0f);
    float oldY = GetY();
    avatar.muoviSu();
    EXPECT_FLOAT_EQ(avatar.getY(), oldY - avatar.getVelocita());
}


// Test movimento verso il basso (muoviGiu)
TEST_F(MovgameTest, MoveDownBasic) {
    avatar.setPos(100.0f, 100.0f);
    float oldY = GetY();
    avatar.muoviGiu();
    EXPECT_FLOAT_EQ(avatar.getY(), oldY + avatar.getVelocita());
}

// Test movimento verso sinistra (muoviSinistra)
TEST_F(MovgameTest, MoveLeftBasic) {
    avatar.setPos(100.0f, 100.0f);
    float oldX = GetX();
    avatar.muoviSinistra();
    EXPECT_FLOAT_EQ(avatar.getX(), oldX - avatar.getVelocita());
}

// Test movimento verso destra (muoviDestra)
TEST_F(MovgameTest, MoveRightBasic) {
    avatar.setPos(100.0f, 100.0f);
    float oldX = GetX();
    avatar.muoviDestra();
    EXPECT_FLOAT_EQ(avatar.getX(), oldX + avatar.getVelocita());
}
