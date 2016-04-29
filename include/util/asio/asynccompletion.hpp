#ifndef UTIL_ASIO_ASYNCCOMPLETION_HPP
#define UTIL_ASIO_ASYNCCOMPLETION_HPP

#include <boost/asio/async_result.hpp>

#include <type_traits>
#include <utility>

namespace util { namespace asio {

// This is basically just async_result_init/async_completion from Asio.
template <class CompletionToken, class Signature>
struct AsyncCompletion {
    explicit AsyncCompletion (CompletionToken&& token)
        : handler(std::move(token))
        , result(handler) {}

    using HandlerType = typename boost::asio::handler_type<CompletionToken, Signature>::type;

    HandlerType handler;
    boost::asio::async_result<HandlerType> result;
};

}} // namespace util::asio

#endif
