#ifndef COUNT_BINARY_DATA_H
#define COUNT_BINARY_DATA_H

#include <QObject>
#include <QSharedDataPointer>
#include <QWidget>
#include <QStack>
enum class data_definition {

    DATA_CHANGED,
    DATA_NOT_CHANGED,
    DATA_ONES,
    DATA_ZEROS
};

//class count_binary_data;

class count_binary_data
{
public:

    count_binary_data();
    int get_num_size();
    data_definition new_count(char data);
    //count_binary_data(const count_binary_data &);
    //count_binary_data &operator=(const count_binary_data &);
    ~count_binary_data();

private:
    //QSharedDataPointer<count_binary_data> data;
    QStack<int> number_counter;
    int number_size;
    data_definition num_type;
    data_definition status;
    data_definition previous_type;
};

#endif // COUNT_BINARY_DATA_H
