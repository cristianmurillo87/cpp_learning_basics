#ifndef INSUFFICIENTFUNDSEXCEPTION_H
#define INSUFFICIENTFUNDSEXCEPTION_H

class InsufficientFundsException : public std::exception
{
public:
	InsufficientFundsException() noexcept = default;
	~InsufficientFundsException() = default;
	virtual const char* what() const noexcept
	{
		return "Not sufficient funds exception";
	}
};

#endif // INSUFFICIENTFUNDSEXCEPTION_H
