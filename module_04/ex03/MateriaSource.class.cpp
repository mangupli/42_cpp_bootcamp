# include "MateriaSource.class.hpp"

/*
 * --------------Constructors------------
 */

MateriaSource::MateriaSource( void ):_stored(0)
{
	//std::cout << "MateriaSource default constructor called" << std::endl;

	for (int i = 0; i < MAX_MATERIA_NUM; ++i)
		this->_sources[i] = 0;

}

MateriaSource::MateriaSource( MateriaSource const & other ):
													_stored(other._stored)
{
	//std::cout << "MateriaSource copy constructor called" << std::endl;

	for (int i = 0; i < MAX_MATERIA_NUM; ++i)
	{
		if (other._sources[i] != 0)
			this->_sources[i] = this->_sources[i]->clone();
		else
			this->_sources[i] = 0;
	}
}

MateriaSource::~MateriaSource( void )
{
	//std::cout << "MateriaSource destructor called" << std::endl;

	for (int i = 0; i < MAX_MATERIA_NUM; ++i)
		delete this->_sources[i];
}

/*
 * ---------------Operators--------------
 */

MateriaSource & MateriaSource::operator=( MateriaSource const & other )
{
	//std::cout << "MateriaSource assignation operator is called" << std::endl;

	if (this == &other)
		return (*this);

	this->_stored = other._stored;

	for (int i = 0; i < MAX_MATERIA_NUM; ++i)
		delete this->_sources[i];

	for (int i = 0; i < MAX_MATERIA_NUM; ++i)
	{
		if (other._sources[i] != 0)
			this->_sources[i] = this->_sources[i]->clone();
		else
			this->_sources[i] = 0;
	}
	return (*this);
}

/*
 * -------------Member functions--------------
 */

int MateriaSource::getStored( void ) const
{
	return this->_stored;
}

void		MateriaSource::learnMateria(AMateria *m)
{
	if (this->_stored == MAX_MATERIA_NUM || m == NULL)
		return ;

	_sources[this->_stored] = m;
	++this->_stored;

	return;
}

AMateria	*MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < MAX_MATERIA_NUM; ++i)
	{
		if (type == this->_sources[i]->getType())
			return (this->_sources[i]->clone());
	}

	return (0);
}