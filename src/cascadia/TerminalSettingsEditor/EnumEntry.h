/*++
Copyright (c) Microsoft Corporation
Licensed under the MIT license.

Module Name:
- EnumEntry.h

Abstract:
- An EnumEntry is intended to be used as a ViewModel for settings
  that are an enum value. It holds an enum name and enum value
  so that any data binding can easily associate one with the other.

Author(s):
- Leon Liang - October 2020

--*/
#pragma once

#include "EnumEntry.g.h"
#include "Utils.h"

namespace winrt::Microsoft::Terminal::Settings::Editor::implementation
{
    struct EnumEntry : EnumEntryT<EnumEntry>
    {
    public:
        EnumEntry(const winrt::hstring enumName, const winrt::Windows::Foundation::IInspectable& enumValue) :
            _EnumName{ enumName },
            _EnumValue{ enumValue } {}

        WINRT_CALLBACK(PropertyChanged, Windows::UI::Xaml::Data::PropertyChangedEventHandler);
        OBSERVABLE_GETSET_PROPERTY(winrt::hstring, EnumName, _PropertyChangedHandlers);
        OBSERVABLE_GETSET_PROPERTY(winrt::Windows::Foundation::IInspectable, EnumValue, _PropertyChangedHandlers);
    };
}
