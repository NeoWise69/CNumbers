#if !(defined BS_INTEGER_H)
#define BS_INTEGER_H

#if (defined BS_INT_USE_STRINGS)
#include <string>
#endif

// Generic integer class, that handles operations with numbers and more...
template<typename Ty>
class basic_integer {
public:
	// Base number type
	using num_t = Ty;
public:
	// Default constructor
	 basic_integer() = default;
	// Default destructor
	~basic_integer() = default;
	// Copy constructor
	basic_integer(const basic_integer&) = default;
public:
	// Numbered constructor
	template<typename U>
	inline basic_integer(U n) noexcept {
		m_value = (num_t)(n);
		m_negative = m_value < 0;
	}
	// Numbered constructor
	inline basic_integer(num_t n) noexcept {
		m_value = n;
		m_negative = m_value < 0;
	}
#if (defined BS_INT_USE_STRINGS)
	// Constructor extracts number from string
	inline basic_integer(const std::string& s) noexcept {
		m_value = atoi(s.c_str());
		m_negative = m_value < 0;
	}
	// Constructor extracts number from string
	inline basic_integer(const char* str) noexcept {
		m_value = atoi(str);
		m_negative = m_value < 0;
	}
#endif
public:
	// Cast to required type
	template <typename U>
	inline U as() const noexcept {
		return (U)(m_value);
	}
public:
	inline operator num_t() const noexcept {
		return m_value;
	}
	template<typename U>
	inline explicit operator U() const noexcept {
		return (U)(m_value);
	}
public:
	template<typename U>
	inline num_t operator+(const U& n) noexcept {
		return m_value + (num_t)(n);
	}
	inline num_t operator+(const num_t& n) noexcept {
		return m_value + n;
	}
	basic_integer operator+(const basic_integer& n) noexcept {
		return basic_integer(m_value + n.m_value);
	}
	template<typename U>
	inline num_t operator-(const U& n) noexcept {
		return m_value - (num_t)(n);
	}
	inline num_t operator-(const num_t& n) noexcept {
		return m_value - n;
	}
	inline basic_integer operator-(const basic_integer& n) noexcept {
		return basic_integer(m_value - n.m_value);
	}
	template<typename U>
	inline num_t operator*(const U& n) noexcept {
		return m_value * (num_t)(n);
	}
	num_t operator*(const num_t& n) noexcept {
		return m_value * n;
	}
	inline basic_integer operator*(const basic_integer& n) noexcept {
		return basic_integer(m_value * n.m_value);
	}
	template<typename U>
	inline num_t operator/(const U& n) noexcept {
		return m_value / (num_t)(n);
	}
	inline num_t operator/(const num_t& n) noexcept {
		return m_value / n;
	}
	inline basic_integer operator/(const basic_integer& n) noexcept {
		return basic_integer(m_value / n.m_value);
	}
public:
	inline bool operator==(const basic_integer& other) noexcept {
		return (m_value == other.m_value && m_negative == other.m_negative);
	}
	inline bool operator==(const num_t& n) noexcept {
		return (m_value == n);
	}
	template<typename U>
	inline bool operator==(const U& n) noexcept {
		return (m_value == (num_t)(n));
	}
	inline bool operator!=(const basic_integer& other) noexcept {
		return (m_value != other.m_value || m_negative != other.m_negative);
	}
	inline bool operator!=(const num_t& n) noexcept {
		return (m_value != n);
	}
	template<typename U>
	inline bool operator!=(const U& n) noexcept {
		return (m_value != (num_t)(n));
	}
	inline bool operator<(const basic_integer& other) noexcept {
		return m_value < other.m_value;
	}
	inline bool operator<(const num_t& n) noexcept {
		return m_value < n;
	}
	template<typename U>
	inline bool operator<(const U& n) noexcept {
		return (m_value < (num_t)(n));
	}
	inline bool operator>(const basic_integer& other) noexcept {
		return m_value > other.m_value;
	}
	inline bool operator>(const num_t& n) noexcept {
		return m_value > n;
	}
	template<typename U>
	inline bool operator>(const U& n) noexcept {
		return (m_value > (num_t)(n));
	}
public:
	inline num_t& operator+=(const num_t& n) noexcept {
		m_value += n;
		m_negative = m_value < 0;
		return m_value;
	}
	inline basic_integer& operator+=(const basic_integer& other) noexcept {
		m_value += other.m_value;
		m_negative = m_value < 0;
		return *this;
	}
	inline num_t& operator-=(const num_t& n) noexcept {
		m_value -= n;
		m_negative = m_value < 0;
		return m_value;
	}
	inline basic_integer& operator-=(const basic_integer& other) noexcept {
		m_value -= other.m_value;
		m_negative = m_value < 0;
		return *this;
	}
	inline num_t& operator*=(const num_t& n) noexcept {
		m_value *= n;
		m_negative = m_value < 0;
		return m_value;
	}
	inline basic_integer& operator*=(const basic_integer& other) noexcept {
		m_value *= other.m_value;
		m_negative = m_value < 0;
		return *this;
	}
	inline num_t& operator/=(const num_t& n) noexcept {
		m_value /= n;
		m_negative = m_value < 0;
		return m_value;
	}
	inline basic_integer& operator/=(const basic_integer& other) noexcept {
		m_value /= other.m_value;
		m_negative = m_value < 0;
		return *this;
	}
public:
	inline basic_integer& operator++() noexcept {
		m_value++;
		m_negative = m_value < 0;
		return *this;
	}
	inline basic_integer  operator++(int) noexcept {
		basic_integer prev = *this;
		++*this;
		return prev;
	}
	inline basic_integer& operator--() noexcept {
		m_value--;
		m_negative = m_value < 0;
		return *this;
	}
	inline basic_integer  operator--(int) noexcept {
		basic_integer prev = *this;
		--*this;
		return prev;
	}
private:
	num_t	m_value;
	bool	m_negative;
};

#endif // !BS_INTEGER_H