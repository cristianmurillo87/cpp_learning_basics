#ifndef ILLEGALBALANCEEXCEPTION_H
#define ILLEGALBALANCEEXCEPTION_H

class IllegalBalanceException : public std::exception
{
public:
	IllegalBalanceException() noexcept = default;
	~IllegalBalanceException() = default;
	virtual const char* what() const noexcept
	{
		return "Illegal balance exception";
	}

};

#endif // ILLEGALBALANCEEXCEPTION_H
