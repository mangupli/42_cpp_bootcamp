#ifndef MATERIASOURCE_CLASS_H
# define MATERIASOURCE_CLASS_H

# include "IMateriaSource.class.hpp"

# define MAX_MATERIA_NUM 4

class MateriaSource: public IMateriaSource {

private:

	int			_stored;
	AMateria	*_sources[MAX_MATERIA_NUM];

public:

	MateriaSource( void );
	MateriaSource( MateriaSource const & other );
	virtual ~MateriaSource( void );

	MateriaSource & operator=( MateriaSource const & other);

	int getStored( void ) const;

	virtual void		learnMateria(AMateria *m);
	virtual AMateria	*createMateria(std::string const & type);

};

#endif