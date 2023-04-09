#ifndef __INTERACTIVEINPUTRETRIEVER_H__
#define __INTERACTIVEINPUTRETRIEVER_H__

#include "InputRetriever.h"

/**
 * @brief The interactive version of the input retriever : the user will be asked several questions to fill the input structure.
 * @author 
 * @since Fri Sep 09 2022
 */
class InteractiveInputRetriever : public InputRetriever
{
public:
    InteractiveInputRetriever();

    /**
     * @brief Asks the user several piece of information in order to create the input.
     * If the user provide any invalid answer, the question will be prompted again, until a correct answer is given.
     * @return An input from the answers of the user.
     */
    Input retrieve();
};

#endif // __INTERACTIVEINPUTRETRIEVER_H__