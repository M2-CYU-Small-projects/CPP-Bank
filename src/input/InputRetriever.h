#ifndef __INPUTRETRIEVER_H__
#define __INPUTRETRIEVER_H__

class Input;

/**
 * @brief Abstract class responsible for retrieving the user input and sending errors otherwise
 * @author 
 * @since Fri Sep 09 2022
 */
class InputRetriever
{
public:
    
    /**
     * Retrieve what the user want to set for the simulation.
     * This method is likely to throw an exception depending on the implementation.
     */
    virtual Input retrieve() = 0;
};
#endif // __INPUTRETRIEVER_H__