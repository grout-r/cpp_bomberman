#ifndef EXCEPTION
# define EXCEPTION

# include <exception>
# include <string>

class					Error : public std::exception 
{
private:
  std::string				message;

public:
  Error(std::string const & what) throw();
  ~Error() throw();
  const char *				what() const throw();
};
#endif
