#include "count_binary_data.h"
#include <QStack>

int count_binary_data::get_num_size() {

    return number_size;

}

count_binary_data::count_binary_data() {

    status = data_definition::DATA_NOT_CHANGED;
    num_type = data_definition::DATA_ONES;
    previous_type = data_definition::DATA_ONES;
    //number_counter.push(1);
    number_size = 1;


}

data_definition count_binary_data::new_count(char data) {

    if (data == 1) {

        num_type = data_definition::DATA_ONES;

    }
    else if (data == 0) {

        num_type = data_definition::DATA_ZEROS;
    }


    if (num_type == previous_type) {

        number_counter.push(1);
        status = data_definition::DATA_NOT_CHANGED;

    }
    else if (num_type != previous_type) {

        number_size = number_counter.size();
        previous_type = num_type;
        status = data_definition::DATA_CHANGED;
        //clear stack
        //number_counter.empty();
        while (!number_counter.empty()) {
            number_counter.pop();
        }
        number_counter.push(1);
    }

    return status;

}


/*count_binary_data::count_binary_data() : data(new count_binary_data)
{





}

count_binary_data::count_binary_data(const count_binary_data &rhs) : data(rhs.data)
{

}

count_binary_data &count_binary_data::operator=(const count_binary_data &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}*/

count_binary_data::~count_binary_data()
{

}
