#pragma once

enum class StatAttribute : uint8_t
{
	None,
	Overflow,
	Underflow
};

template< typename T >
class Stat
{
private:
	T value;
	T minimum = 0;
	T maximum = ~0;

private:
	constexpr T clamp(T value, T minimum, T maximum)
	{
		return (value < minimum) ? minimum : (value > maximum) ? maximum : value;
	}
	
	void set(T input)
	{
		this->value = clamp(input, this->minimum, this->maximum);
	}

public:
	constexpr Stat(void) = default;

	constexpr explicit Stat(T input)
		: value(input), minimum(0), maximum(~0)
	{
	};

	constexpr Stat(T input, T minimum, T maximum)
		: value(clamp(input, minimum, maximum)), minimum(minimum), maximum(maximum)
	{
	};

	T getValue(void) const
	{
		return this->value;
	}

	T getMaximum(void) const
	{
		return this->maximum;
	}

	T getMinimum(void) const
	{
		return this->minimum;
	}
	
	void setMaximum(const T maximum)
	{
		this->maximum = maximum;
	}
		
	void setMinimum(const T minimum)
	{
		this->minimum = minimum;
	}
	
	void add(T input, StatAttribute & attribute)
	{
		if ((this->value + input) > this->maximum)
		{
			this->value = this->maximum;
			attribute = StatAttribute::Overflow;
		}
		else if ((this->value + input) < this->minimum)
		{
			this->value = this->minimum;
			attribute = StatAttribute::Underflow;
		}
		else
		{
			this->value += input;
			attribute = StatAttribute::None;
		}
	}

	void set(T input, StatAttribute & attribute)
	{
		if (input > this->maximum)
		{
			this->value = this->maximum;
			attribute = StatAttribute::Overflow;
		}
		else if (input < this->minimum)
		{
			this->value = this->minimum;
			attribute = StatAttribute::Underflow;
		}
		else
		{
			this->value = input;
			attribute = StatAttribute::None;
		}
	}

	constexpr explicit operator T(void) const
	{
		return this->value;
	}

	Stat & operator =(T input)
	{
		this->set(input);
		return *this;
	}

	Stat & operator +=(T input)
	{
		this->set(this->value + input);
		return *this;
	}

	Stat & operator -=(T input)
	{
		this->set(this->value - input);
		return *this;
	}

	Stat & operator *=(T input)
	{
		this->set(this->value * input);
		return *this;
	}

	Stat & operator /=(T input)
	{
		this->set(this->value / input);
		return *this;
	}
};

//
// Arithmetic operators
//

template< typename T >
constexpr Stat<T> operator +(const Stat<T> & left, T right)
{
	return Stat<T>(left.getValue() + right, left.getMinimum(), left.getMaximum());
}

template< typename T >
constexpr Stat<T> operator +(T left, const Stat<T> & right)
{
	return Stat<T>(left + right.getValue(), right.getMinimum(), right.getMaximum());
}

template< typename T >
constexpr Stat<T> operator -(const Stat<T> & left, T right)
{
	return Stat<T>(left.getValue() - right, left.getMinimum(), left.getMaximum());
}

template< typename T >
constexpr Stat<T> operator -(T left, const Stat<T> & right)
{
	return Stat<T>(left - right.getValue(), right.getMinimum(), right.getMaximum());
}

template< typename T >
constexpr Stat<T> operator *(const Stat<T> & left, T right)
{
	return Stat<T>(left.getValue() * right, left.getMinimum(), left.getMaximum());
}

template< typename T >
constexpr Stat<T> operator *(T left, const Stat<T> & right)
{
	return Stat<T>(left * right.getValue(), right.getMinimum(), right.getMaximum());
}

template< typename T >
constexpr Stat<T> operator /(const Stat<T> & left, T right)
{
	return Stat<T>(left.getValue() / right, left.getMinimum(), left.getMaximum());
}

template< typename T >
constexpr Stat<T> operator /(T left, const Stat<T> & right)
{
	return Stat<T>(left / right.getValue(), right.getMinimum(), right.getMaximum());
}

//
// Logic operators
//

template< typename T >
constexpr bool operator ==(T left, const Stat<T> & right)
{
	return (left == right.getValue());
}

template< typename T >
constexpr bool operator ==(const Stat<T> & left, T right)
{
	return (left.getValue() == right);
}

template< typename T >
constexpr bool operator !=(T left, const Stat<T> & right)
{
	return (left != right.getValue());
}

template< typename T >
constexpr bool operator !=(const Stat<T> & left, T right)
{
	return (left.getValue() != right);
}

template< typename T >
constexpr bool operator >(T left, const Stat<T> & right)
{
	return (left > right.getValue());
}

template< typename T >
constexpr bool operator >(const Stat<T> & left, T right)
{
	return (left.getValue() > right);
}

template< typename T >
constexpr bool operator <(T left, const Stat<T> & right)
{
	return (left < right.getValue());
}

template< typename T >
constexpr bool operator <(const Stat<T> & left, T right)
{
	return (left.getValue() < right);
}

template< typename T >
constexpr bool operator >=(T left, const Stat<T> & right)
{
	return (left >= right.getValue());
}

template< typename T >
constexpr bool operator >=(const Stat<T> & left, T right)
{
	return (left.getValue() >= right);
}

template< typename T >
constexpr bool operator <=(T left, const Stat<T> & right)
{
	return (left <= right.getValue());
}

template< typename T >
constexpr bool operator <=(const Stat<T> & left, T right)
{
	return (left.getValue() <= right);
}
