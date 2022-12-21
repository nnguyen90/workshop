#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
namespace sdds {

	struct Population
	{	
		char postal_code[4];
		int population;
	};

	bool load(const char* file_name);
	void display();
	void deallocateMemory();
}
#endif // SDDS_POPULATION_H_