#include "gtest/gtest.h"
#include <cstring>
#include "aux_functions.h"
#define _USE_MATH_DEFINES
#include "math.h"

extern "C"
{
    #include <time.h>
    #include <stdlib.h>
    #include "../src/Aux_Func.h"
}


TEST(TestCaseName, TestName) {
    EXPECT_EQ(1, 1);
    EXPECT_TRUE(true);

    // Inicializações do Projeto

    // Randomiza, eventualmente.
    srand((unsigned int) time(NULL));
}


TEST(TestcreateOneFr52Deck, TestMatchFr52Deck) {
    ListCardNodePtr expectedDeck = NULL;
    ListCardNodePtr actualDeck = NULL;

    createOneFr52Deck(&actualDeck);
    ReadFileOfOneFr52Deck(&expectedDeck);
    ASSERT_TRUE(ListMatch(actualDeck, expectedDeck));
}


TEST(TestshuffleOneFr52Deck, TestShuffleFr52Deck) {
    ListCardNodePtr expectedDeck = NULL;
    ListCardNodePtr actualDeck = NULL;

    ReadFileOfOneFr52Deck(&actualDeck);
    shuffle(&actualDeck);
    
    readFileOfShuffledFr52Deck(&expectedDeck);
    ASSERT_TRUE(ListMatch(actualDeck, expectedDeck));
    // Verifica se os nós foram trocados
    ASSERT_TRUE(ListNodeAddressesMismatch(actualDeck, expectedDeck));
    // Verifica se algum dos ponteiros é nulo
    ASSERT_TRUE(NullPointerTest(actualDeck, expectedDeck));
    
}

