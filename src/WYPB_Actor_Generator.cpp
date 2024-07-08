#include <new>
#include "WYPB_Actor_Generator.hpp"


WYPB_Actor_Generator::WYPB_Actor_Generator()
{

}


WYPB_Actor_Generator::~WYPB_Actor_Generator()
{

}


WYPB_Actor* WYPB_Actor_Generator::create_actor()
{
    return new(std::nothrow) WYPB_Actor;
}