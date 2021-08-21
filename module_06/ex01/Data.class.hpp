#ifndef DATA_CLASS_H
# define DATA_CLASS_H

# include <string>


class Data {

private:

    std::string _importantData;

public:

	Data( void ):_importantData("I'm very important data"){}
	Data( Data const & ){}
	~Data( void ){}

	Data & operator=( Data const & ){ return *this; }

    std::string getImportantData() { return this->_importantData; }
    void        setImportantData( std::string data ) { this->_importantData = data; }
 
};


#endif