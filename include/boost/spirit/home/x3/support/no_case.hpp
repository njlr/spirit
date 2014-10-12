/*=============================================================================
    Copyright (c) 2001-2014 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(BOOST_SPIRIT_X3_SUPPORT_NO_CASE_SEPT_24_2014_1125PM)
#define BOOST_SPIRIT_X3_SUPPORT_NO_CASE_SEPT_24_2014_1125PM

#if defined(_MSC_VER)
#pragma once
#endif
#include <boost/spirit/home/x3/support/unused.hpp>
#include <boost/spirit/home/x3/support/context.hpp>
#include <boost/spirit/home/x3/char/char_class_tags.hpp>

namespace boost { namespace spirit { namespace x3
{
    struct no_case_tag {};

    template <typename Encoding>
    struct case_compare
    {
        int32_t operator()(typename Encoding::char_type const lc, typename Encoding::char_type const rc) const
        {
            return lc - rc;
        }


        template <typename CharClassTag>
        CharClassTag get_char_class_tag(CharClassTag tag) const
        {
            return tag;
        }
    };

    template <typename Encoding>
    struct no_case_compare
    {
        int32_t operator()(typename Encoding::char_type const lc, typename Encoding::char_type const rc) const
        {
            return Encoding::islower(rc) ? Encoding::tolower(lc) - rc : Encoding::toupper(lc) - rc;
        }
        
        template <typename CharClassTag>
        CharClassTag get_char_class_tag(CharClassTag tag) const
        {
            return tag;
        }
        
        alpha_tag get_char_class_tag(lower_tag ) const
        {
            return alpha_tag();
        }
        
        alpha_tag get_char_class_tag(upper_tag ) const
        {
            return alpha_tag();
        }

    };

    template <typename Encoding>
    case_compare<Encoding> get_case_compare_impl(unused_type const&)
    {
        return case_compare<Encoding>();
    }

    template <typename Encoding>
    no_case_compare<Encoding> get_case_compare_impl(no_case_tag const&)
    {
        return no_case_compare<Encoding>();
    }

    template <typename Encoding, typename Context>
    inline auto get_case_compare(Context const& context)
        ->decltype(get_case_compare_impl<Encoding>(x3::get<no_case_tag>(context)))
    {
        return get_case_compare_impl<Encoding>(x3::get<no_case_tag>(context));
    }
    no_case_tag const no_case_compare_ = no_case_tag();

}}}

#endif
