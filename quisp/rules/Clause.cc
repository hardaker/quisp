/** \file Clause.cc
 *
 *  \authors takaaki matsuo, cldurand
 *  \date 2018/07/03
 *
 *  \brief Clause
 */
#include "Clause.h"
#include "tools.h"

namespace quisp {
namespace rules {

bool FidelityClause::check(qnicResources* resources) const {
    stationaryQubit* qubit = NULL;
    checkQnic();//This is not doing anything...
    if(qubit = getQubit(resources, qnic_type, qnic_id, partner, resource)){
        return (qubit->getFidelity() >= threshold);
    }
    return false;
}
bool MeasureCountClause::check(qnicResources* resources) const {
    EV<<"MeasureCountClause invoked.\n";
    if(current_count<max_count){
        current_count++;//Increment measured counter.
        EV<<"Measurement count is now "<<current_count<<" < "<<max_count<<"\n";
        return true;
    }
    else
        return false;
}


Clause *EXAMPLE_CLAUSE = new FidelityClause(0,0,.6);

} // namespace rules
} // namespace quisp
