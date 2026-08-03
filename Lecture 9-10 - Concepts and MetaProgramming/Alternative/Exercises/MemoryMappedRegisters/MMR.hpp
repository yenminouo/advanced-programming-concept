/*****************************************/
/* Copyright: DevelEdu 2015              */
/* Author: sha                           */
/*****************************************/
#ifndef MMR_HPP_
#define MMR_HPP_

#include <cstdint>

template<size_t N>
struct Binary
{
  enum{ value = Binary<N/10>::value << 1 | N%10 };
};

template<>
struct Binary < 0 >
{
  enum  { value = 0 };
};


// 1.2.1 Reading policy




// 1.2.2 Writing policy



// 1.2.3 Reading / writing policy



// 1.3.1 Default Translator - already done for you
struct DefaultTranslator
{
  uint32_t out(uint32_t o)
  {
    return o;
  }
  
  typedef uint32_t InRetType;
  uint32_t in(uint32_t i)
  {
    return i;
  }
};




// 1.4.1 - 1.4.4 BitField





// 1.3.2 State Translator




// 1.3.3 Prescale Translator






#endif
