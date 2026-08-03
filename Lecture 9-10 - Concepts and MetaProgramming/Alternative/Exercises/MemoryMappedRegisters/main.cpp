/*****************************************/
/* Copyright: DevelEdu 2015              */
/* Author: sha                           */
/*****************************************/
#include <iostream>
#include <bitset>
#include "MMR.hpp"


/***************************************************************/
/** For simple test purposes!!!
 */

#if defined(_MSC_VER)
#define FUNC __FUNCTION__
#else
#define FUNC __PRETTY_FUNCTION__
#endif

#define ERROR(txt) do  {  std::cout << "Error occured in: " << FUNC << " (" << __FILE__ << ":" << __LINE__ << ") - " << txt << std::endl; \
  } while(0)

#define REQUIRE_BITS(a, b) do  { if(a != b)    {      ERROR("Values different : " << std::bitset<32>(a) << " != " << std::bitset<32>(b)); \
    }                                                                   \
  }                                                                     \
  while(0)

#define REQUIRE_VALUE(a, b) do  { if(a != b)    {      ERROR("Values different : " << a << " != " << b); \
    }                                                                   \
  }                                                                     \
  while(0)


/**
 * 1.2.1 Simple test for reading policy
 */
/*
void testROPolicy()
{
  uint32_t reg = Binary<1011101111>::value;
  
  REQUIRE_BITS(RO::read(&reg, 1, 4), Binary<111>::value);
  REQUIRE_BITS(RO::read(&reg, 5, 5), Binary<1>::value) ;
}
*/
  
/**
 * 1.2.2 Simple test for writing policy
 */
/*
void testWOPolicy()
{
  uint32_t reg = Binary<1011101111>::value;

  WO::write(&reg, 1, 5, Binary<10101>::value);
  REQUIRE_BITS(reg, Binary<101010>::value);

  reg = 0;
  
  WO::write(&reg, 5, 7, Binary<111111>::value);
  REQUIRE_BITS(reg, Binary<11100000>::value);
}
*/


/**
 * 1.2.3 Simple test for writing policy
 */
/*
void testRWPolicy()
{
  uint32_t reg = Binary<1011101111>::value;
  RW::write(&reg, 1, 5, Binary<11101>::value);
  REQUIRE_BITS(reg, Binary<1011111011>::value);
}
*/


/**
 * 1.3.2 Simple test for State translater
 */
/*
std::ostream& operator<<(std::ostream& os, State s)
{
  switch(s)
  {
    case State::ENABLE:
      os << "ENABLE";
      break;
    case State::DISABLE:
      os << "DISABLE";
      break;
  }
  
  return os;
}


void testStateTranslator()
{
  StateTranslator<1, 0> st;

  REQUIRE_VALUE(st.in(1), State::ENABLE);
  REQUIRE_VALUE(st.in(0), State::DISABLE);
  REQUIRE_VALUE(st.out(State::ENABLE), 1);
  REQUIRE_VALUE(st.out(State::DISABLE), 0);
}
*/


/**
 * 1.3.3 Simple test for Prescale translater
 */
/*
std::ostream& operator<<(std::ostream& os, Prescale s)
{
  switch(s)
  {
    case Prescale::DIV_FACT_2:
      os << "Div by factor 2";
      break;
    case Prescale::DIV_FACT_4:
      os << "Div by factor 4";
      break;
    case Prescale::DIV_FACT_8:
      os << "Div by factor 8";
      break;
    case Prescale::DIV_FACT_16:
      os << "Div by factor 16";
      break;
    case Prescale::DIV_FACT_32:
      os << "Div by factor 32";
      break;
    case Prescale::DIV_FACT_64:
      os << "Div by factor 64";
      break;
    case Prescale::DIV_FACT_128:
      os << "Div by factor 128";
      break;
  }
  
  return os;
}

void testPrescaleTranslator()
{
  PrescaleTranslator pt;

  REQUIRE_VALUE(pt.in(Binary<011>::value), Prescale::DIV_FACT_8);
  REQUIRE_VALUE(pt.in(Binary<110>::value), Prescale::DIV_FACT_64);
  REQUIRE_VALUE(pt.out(Prescale::DIV_FACT_8), Binary<011>::value);
  REQUIRE_VALUE(pt.out(Prescale::DIV_FACT_64), Binary<110>::value);
}
*/

/***************************************************************/
/** Code starts!!!
 */


/** 1.4.4 - Register definition, requirs BitField<> defined
 */
/*
namespace Periph
{
  struct Adc
  {
    enum {ADEN =0, // Bit fields...
          ADSC = 1,
          ADATE=2,
          ADIF=3,
          ADIE=4,
          ADPS0=5,
          ADPS2=7
    };

    Adc(size_t address) : address_(address) 
    {}
    
    auto state() const          { return BitField<RW, ADEN, ADEN, StateTranslator<1, 0> >(address_);}
    void start() const          { (BitField<RW, ADSC, ADSC>(address_)) = 1; }
    auto autoTrigger() const    { return BitField<RW, ADATE, ADATE, StateTranslator<1, 0> >(address_);}
    auto interruptFlag() const  { return BitField<RW, ADIF, ADIF, StateTranslator<1, 0> >(address_);}
    auto interruptState() const { return BitField<RW, ADIE, ADIE, StateTranslator<1, 0> >(address_);}
    auto prescale() const       { return BitField<RW, ADPS0, ADPS2, PrescaleTranslator>(address_);}

  private:
    const size_t address_;
  };
}


void testDynamicAddress()
{
  uint32_t reg = 0;
  const Periph::Adc adc(reinterpret_cast<size_t>(&reg));

  adc.start();
  //adc.state() = 1; // Compilation error - not allowed
  adc.state()= State::ENABLE;
  adc.prescale() = Prescale::DIV_FACT_32;

  State s = adc.state();
  if(s == State::ENABLE)
    std::cout << "..." << std::endl;

  std::cout << "Binary value of register: " << std::bitset<32>(reg) << std::endl;
}


void testHardcodedAddress()
{
  const Periph::Adc adc(1000000);

  adc.start();
  //adc.state() = 1; // Compilation error - not allowed
  adc.state()= State::ENABLE;
  adc.prescale() = Prescale::DIV_FACT_32;

  State s = adc.state();
  if(s == State::ENABLE)
    std::cout << "..." << std::endl;
}
*/
  
int main(int argc, char* argv[])
{
  //testROPolicy();             // 1.2.1 Simple test for reading policy
  //testWOPolicy();             // 1.2.2 Simple test for writing policy
  //testRWPolicy();             // 1.2.3 Simple test for writing policy

  //testStateTranslator();      // 1.3.2 Simple test for State translater
  //testPrescaleTranslator();   // 1.3.3 Simple test for Prescale translater
  
  //testDynamicAddress();       // 1.4.4 Using BitField<> template
  //testHardcodedAddress(); // Generates run-time error! Comment out to run program
  
  return 0;
  
}
