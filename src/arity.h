template <typename T> struct functionParamCount {};
template <typename R, typename ..A> struct functionParamCount<R(A...)> {
	static const size_t count = sizeof...(A);
};
