#if !(defined BS_FLOATING_H)
#define BS_FLOATING_H

#if (defined BS_FP_USE_STRINGS)
#include <string>
#endif

// Generic floating-pointer number class, that handles some extra stuff...
template<typename Ty>
class basic_floating_point {
public:
	using num_t = Ty;
public:
	// Default constructor
	basic_floating_point() = default;
	// Default destructor
	~basic_floating_point() = default;
	// Copy constructor
	basic_floating_point(const basic_floating_point&) = default;
public:
	// Double precision epsilon
	inline static constexpr basic_floating_point<double> epsd() noexcept { return basic_floating_point<double>(2.2204460492503131e-016); }
	// Float precision epsilon
	inline static constexpr basic_floating_point<float> epsf() noexcept { return basic_floating_point<float>(1.192092896e-07F); }
	// Double precision max number
	inline static constexpr basic_floating_point<double> maxd() noexcept { return basic_floating_point<double>(1.7976931348623158e+308); }
	// Float precision max number
	inline static constexpr basic_floating_point<float> maxf() noexcept { return basic_floating_point<float>(3.402823466e+38F); }
	// Number of decimal digits (double)
	inline static constexpr basic_floating_point ddigsd() noexcept { return basic_floating_point(17); }
	// Number of decimal digits (float)
	inline static constexpr basic_floating_point ddigsf() noexcept { return basic_floating_point(9); }
public:
	// Numbered constructor
	template<typename U>
	inline basic_floating_point(U n) noexcept {
		m_value = (num_t)(n);
		m_negative = m_value < 0;
	}
	// Numbered constructor
	inline basic_floating_point(num_t n) noexcept {
		m_value = n;
		m_negative = m_value < 0;
	}
#if (defined BS_FP_USE_STRINGS)
	// Constructor extracts number from string
	inline basic_floating_point(const std::string& s) noexcept {
		m_value = (num_t)(atof)(s.c_str());
		m_negative = m_value < 0;
	}
	// Constructor extracts number from string
	inline basic_floating_point(const char* str) noexcept {
		m_value = (num_t)(atof)(str);
		m_negative = m_value < 0;
	}
#endif
public:
	// Cast to required type
	template <typename U>
	inline U as(U&) const noexcept {
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
	basic_floating_point operator+(const basic_floating_point& n) noexcept {
		return basic_floating_point(m_value + n.m_value);
	}
	template<typename U>
	inline num_t operator-(const U& n) noexcept {
		return m_value - (num_t)(n);
	}
	inline num_t operator-(const num_t& n) noexcept {
		return m_value - n;
	}
	inline basic_floating_point operator-(const basic_floating_point& n) noexcept {
		return basic_floating_point(m_value - n.m_value);
	}
	template<typename U>
	inline num_t operator*(const U& n) noexcept {
		return m_value * (num_t)(n);
	}
	num_t operator*(const num_t& n) noexcept {
		return m_value * n;
	}
	inline basic_floating_point operator*(const basic_floating_point& n) noexcept {
		return basic_floating_point(m_value * n.m_value);
	}
	template<typename U>
	inline num_t operator/(const U& n) noexcept {
		return m_value / (num_t)(n);
	}
	inline num_t operator/(const num_t& n) noexcept {
		return m_value / n;
	}
	inline basic_floating_point operator/(const basic_floating_point& n) noexcept {
		return basic_floating_point(m_value / n.m_value);
	}
public:
	inline bool operator==(const basic_floating_point& other) noexcept {
		return (__bs_compare(other.m_value) && m_negative == other.m_negative);
	}
	inline bool operator==(const num_t& n) noexcept {
		return (__bs_compare(n));
	}
	template<typename U>
	inline bool operator==(const U& n) noexcept {
		return (__bs_compare((num_t)(n)));
	}
	inline bool operator!=(const basic_floating_point& other) noexcept {
		return (!__bs_compare(other.m_value) || m_negative != other.m_negative);
	}
	inline bool operator!=(const num_t& n) noexcept {
		return (!__bs_compare(n));
	}
	template<typename U>
	inline bool operator!=(const U& n) noexcept {
		return (!__bs_compare((num_t)(n)));
	}
	inline bool operator<(const basic_floating_point& other) noexcept {
		return m_value < other.m_value;
	}
	inline bool operator<(const num_t& n) noexcept {
		return m_value < n;
	}
	template<typename U>
	inline bool operator<(const U& n) noexcept {
		return (m_value < (num_t)(n));
	}
	inline bool operator>(const basic_floating_point& other) noexcept {
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
	inline basic_floating_point& operator+=(const basic_floating_point& other) noexcept {
		m_value += other.m_value;
		m_negative = m_value < 0;
		return *this;
	}
	inline num_t& operator-=(const num_t& n) noexcept {
		m_value -= n;
		m_negative = m_value < 0;
		return m_value;
	}
	inline basic_floating_point& operator-=(const basic_floating_point& other) noexcept {
		m_value -= other.m_value;
		m_negative = m_value < 0;
		return *this;
	}
	inline num_t& operator*=(const num_t& n) noexcept {
		m_value *= n;
		m_negative = m_value < 0;
		return m_value;
	}
	inline basic_floating_point& operator*=(const basic_floating_point& other) noexcept {
		m_value *= other.m_value;
		m_negative = m_value < 0;
		return *this;
	}
	inline num_t& operator/=(const num_t& n) noexcept {
		m_value /= n;
		m_negative = m_value < 0;
		return m_value;
	}
	inline basic_floating_point& operator/=(const basic_floating_point& other) noexcept {
		m_value /= other.m_value;
		m_negative = m_value < 0;
		return *this;
	}
public:
	inline basic_floating_point& operator++() noexcept {
		m_value++;
		m_negative = m_value < 0;
		return *this;
	}
	inline basic_floating_point  operator++(int) noexcept {
		basic_floating_point prev = *this;
		++* this;
		return prev;
	}
	inline basic_floating_point& operator--() noexcept {
		m_value--;
		m_negative = m_value < 0;
		return *this;
	}
	inline basic_floating_point  operator--(int) noexcept {
		basic_floating_point prev = *this;
		--* this;
		return prev;
	}
private:
	inline bool __bs_compare(num_t other) const noexcept {
		return fabs(m_value - other) < basic_floating_point::epsf(); // epsf() used for avoid useless precision and performance loss
	}
private:
	num_t	m_value;
	bool	m_negative;
};

#endif // !BS_FLOATING_H
