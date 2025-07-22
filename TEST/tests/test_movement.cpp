#include <gtest/gtest.h>
#include "../pch.h"  // contiene la definizione della classe Movement

// ---------------------
// Test Movement (mappa)
// ---------------------

TEST(MovementTest, InitialPosition) {
    Movement mov;  // Dichiaro oggetto della classe Movement

    // Verifica che la posizione iniziale sia quella nel costruttore
    ASSERT_FLOAT_EQ(mov.pos_x, 907.0f);
    ASSERT_FLOAT_EQ(mov.pos_y, 439.0f);
    ASSERT_FLOAT_EQ(mov.step, 1.0f);
}

TEST(MovementTest, MoveUp) {
    Movement mov;

    // Simula il movimento "up" modificando direttamente pos_y
    mov.pos_y -= mov.step;

    // Controlla che pos_y sia diminuito di step
    ASSERT_FLOAT_EQ(mov.pos_y, 439.0f - 1.0f);
}

TEST(MovementTest, Boundaries) {
    Movement mov;

    // Controlla i limiti iniziali
    ASSERT_FLOAT_EQ(mov.max_heightchngd, 330.0f);
    ASSERT_FLOAT_EQ(mov.min_heightchngd, 764.0f);
}
