#include <tuple>

template <typename ReturnType, typename... Args>
struct function_traits_defs
{
	static constexpr size_t arity = sizeof...(Args);

	using result_type = ReturnType;

	template <size_t i>
	struct arg
	{
		using type = typename std::tuple_element<i, std::tuple<Args...>>::type;
	};
};

template <typename T>
struct function_traits_impl;

template <typename ReturnType, typename... Args>
struct function_traits_impl<ReturnType(Args...)>
	: function_traits_defs<ReturnType, Args...> {};

template <typename ReturnType, typename... Args>
struct function_traits_impl<ReturnType(*)(Args...)>
	: function_traits_defs<ReturnType, Args...> {};

template <typename ClassType, typename ReturnType, typename... Args>
struct function_traits_impl<ReturnType(ClassType::*)(Args...)>
	: function_traits_defs<ReturnType, Args...> {};

template <typename ClassType, typename ReturnType, typename... Args>
struct function_traits_impl<ReturnType(ClassType::*)(Args...) const>
	: function_traits_defs<ReturnType, Args...> {};


template <typename T, typename V = void>
struct function_traits
	: function_traits_impl<T> {};

template <typename T>
struct function_traits<T, decltype((void)&T::operator())>
	: function_traits_impl<decltype(&T::operator())> {};
