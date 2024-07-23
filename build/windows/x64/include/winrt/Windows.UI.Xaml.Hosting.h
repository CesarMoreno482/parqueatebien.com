// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.220418.1

#pragma once
#ifndef WINRT_Windows_UI_Xaml_Hosting_H
#define WINRT_Windows_UI_Xaml_Hosting_H
#include "winrt/base.h"
static_assert(winrt::check_version(CPPWINRT_VERSION, "2.0.220418.1"), "Mismatched C++/WinRT headers.");
#define CPPWINRT_VERSION "2.0.220418.1"
#include "winrt/Windows.UI.Xaml.h"
#include "winrt/impl/Windows.UI.Composition.2.h"
#include "winrt/impl/Windows.UI.WindowManagement.2.h"
#include "winrt/impl/Windows.UI.Xaml.2.h"
#include "winrt/impl/Windows.UI.Xaml.Controls.2.h"
#include "winrt/impl/Windows.UI.Xaml.Hosting.2.h"
namespace winrt::impl
{
    template <typename D> auto consume_Windows_UI_Xaml_Hosting_IElementCompositionPreviewStatics<D>::GetElementVisual(winrt::Windows::UI::Xaml::UIElement const& element) const
    {
        void* result{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::UI::Xaml::Hosting::IElementCompositionPreviewStatics)->GetElementVisual(*(void**)(&element), &result));
        return winrt::Windows::UI::Composition::Visual{ result, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_UI_Xaml_Hosting_IElementCompositionPreviewStatics<D>::GetElementChildVisual(winrt::Windows::UI::Xaml::UIElement const& element) const
    {
        void* result{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::UI::Xaml::Hosting::IElementCompositionPreviewStatics)->GetElementChildVisual(*(void**)(&element), &result));
        return winrt::Windows::UI::Composition::Visual{ result, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_UI_Xaml_Hosting_IElementCompositionPreviewStatics<D>::SetElementChildVisual(winrt::Windows::UI::Xaml::UIElement const& element, winrt::Windows::UI::Composition::Visual const& visual) const
    {
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::UI::Xaml::Hosting::IElementCompositionPreviewStatics)->SetElementChildVisual(*(void**)(&element), *(void**)(&visual)));
    }
    template <typename D> auto consume_Windows_UI_Xaml_Hosting_IElementCompositionPreviewStatics<D>::GetScrollViewerManipulationPropertySet(winrt::Windows::UI::Xaml::Controls::ScrollViewer const& scrollViewer) const
    {
        void* result{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::UI::Xaml::Hosting::IElementCompositionPreviewStatics)->GetScrollViewerManipulationPropertySet(*(void**)(&scrollViewer), &result));
        return winrt::Windows::UI::Composition::CompositionPropertySet{ result, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_UI_Xaml_Hosting_IElementCompositionPreviewStatics2<D>::SetImplicitShowAnimation(winrt::Windows::UI::Xaml::UIElement const& element, winrt::Windows::UI::Composition::ICompositionAnimationBase const& animation) const
    {
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::UI::Xaml::Hosting::IElementCompositionPreviewStatics2)->SetImplicitShowAnimation(*(void**)(&element), *(void**)(&animation)));
    }
    template <typename D> auto consume_Windows_UI_Xaml_Hosting_IElementCompositionPreviewStatics2<D>::SetImplicitHideAnimation(winrt::Windows::UI::Xaml::UIElement const& element, winrt::Windows::UI::Composition::ICompositionAnimationBase const& animation) const
    {
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::UI::Xaml::Hosting::IElementCompositionPreviewStatics2)->SetImplicitHideAnimation(*(void**)(&element), *(void**)(&animation)));
    }
    template <typename D> auto consume_Windows_UI_Xaml_Hosting_IElementCompositionPreviewStatics2<D>::SetIsTranslationEnabled(winrt::Windows::UI::Xaml::UIElement const& element, bool value) const
    {
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::UI::Xaml::Hosting::IElementCompositionPreviewStatics2)->SetIsTranslationEnabled(*(void**)(&element), value));
    }
    template <typename D> auto consume_Windows_UI_Xaml_Hosting_IElementCompositionPreviewStatics2<D>::GetPointerPositionPropertySet(winrt::Windows::UI::Xaml::UIElement const& targetElement) const
    {
        void* result{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::UI::Xaml::Hosting::IElementCompositionPreviewStatics2)->GetPointerPositionPropertySet(*(void**)(&targetElement), &result));
        return winrt::Windows::UI::Composition::CompositionPropertySet{ result, take_ownership_from_abi };
    }
    template <typename D> auto consume_Windows_UI_Xaml_Hosting_IElementCompositionPreviewStatics3<D>::SetAppWindowContent(winrt::Windows::UI::WindowManagement::AppWindow const& appWindow, winrt::Windows::UI::Xaml::UIElement const& xamlContent) const
    {
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::UI::Xaml::Hosting::IElementCompositionPreviewStatics3)->SetAppWindowContent(*(void**)(&appWindow), *(void**)(&xamlContent)));
    }
    template <typename D> auto consume_Windows_UI_Xaml_Hosting_IElementCompositionPreviewStatics3<D>::GetAppWindowContent(winrt::Windows::UI::WindowManagement::AppWindow const& appWindow) const
    {
        void* result{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::UI::Xaml::Hosting::IElementCompositionPreviewStatics3)->GetAppWindowContent(*(void**)(&appWindow), &result));
        return winrt::Windows::UI::Xaml::UIElement{ result, take_ownership_from_abi };
    }
#ifndef WINRT_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, winrt::Windows::UI::Xaml::Hosting::IElementCompositionPreview> : produce_base<D, winrt::Windows::UI::Xaml::Hosting::IElementCompositionPreview>
    {
    };
#endif
#ifndef WINRT_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, winrt::Windows::UI::Xaml::Hosting::IElementCompositionPreviewStatics> : produce_base<D, winrt::Windows::UI::Xaml::Hosting::IElementCompositionPreviewStatics>
    {
        int32_t __stdcall GetElementVisual(void* element, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<winrt::Windows::UI::Composition::Visual>(this->shim().GetElementVisual(*reinterpret_cast<winrt::Windows::UI::Xaml::UIElement const*>(&element)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetElementChildVisual(void* element, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<winrt::Windows::UI::Composition::Visual>(this->shim().GetElementChildVisual(*reinterpret_cast<winrt::Windows::UI::Xaml::UIElement const*>(&element)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetElementChildVisual(void* element, void* visual) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetElementChildVisual(*reinterpret_cast<winrt::Windows::UI::Xaml::UIElement const*>(&element), *reinterpret_cast<winrt::Windows::UI::Composition::Visual const*>(&visual));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetScrollViewerManipulationPropertySet(void* scrollViewer, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<winrt::Windows::UI::Composition::CompositionPropertySet>(this->shim().GetScrollViewerManipulationPropertySet(*reinterpret_cast<winrt::Windows::UI::Xaml::Controls::ScrollViewer const*>(&scrollViewer)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef WINRT_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, winrt::Windows::UI::Xaml::Hosting::IElementCompositionPreviewStatics2> : produce_base<D, winrt::Windows::UI::Xaml::Hosting::IElementCompositionPreviewStatics2>
    {
        int32_t __stdcall SetImplicitShowAnimation(void* element, void* animation) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetImplicitShowAnimation(*reinterpret_cast<winrt::Windows::UI::Xaml::UIElement const*>(&element), *reinterpret_cast<winrt::Windows::UI::Composition::ICompositionAnimationBase const*>(&animation));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetImplicitHideAnimation(void* element, void* animation) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetImplicitHideAnimation(*reinterpret_cast<winrt::Windows::UI::Xaml::UIElement const*>(&element), *reinterpret_cast<winrt::Windows::UI::Composition::ICompositionAnimationBase const*>(&animation));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetIsTranslationEnabled(void* element, bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetIsTranslationEnabled(*reinterpret_cast<winrt::Windows::UI::Xaml::UIElement const*>(&element), value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetPointerPositionPropertySet(void* targetElement, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<winrt::Windows::UI::Composition::CompositionPropertySet>(this->shim().GetPointerPositionPropertySet(*reinterpret_cast<winrt::Windows::UI::Xaml::UIElement const*>(&targetElement)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef WINRT_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, winrt::Windows::UI::Xaml::Hosting::IElementCompositionPreviewStatics3> : produce_base<D, winrt::Windows::UI::Xaml::Hosting::IElementCompositionPreviewStatics3>
    {
        int32_t __stdcall SetAppWindowContent(void* appWindow, void* xamlContent) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetAppWindowContent(*reinterpret_cast<winrt::Windows::UI::WindowManagement::AppWindow const*>(&appWindow), *reinterpret_cast<winrt::Windows::UI::Xaml::UIElement const*>(&xamlContent));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetAppWindowContent(void* appWindow, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<winrt::Windows::UI::Xaml::UIElement>(this->shim().GetAppWindowContent(*reinterpret_cast<winrt::Windows::UI::WindowManagement::AppWindow const*>(&appWindow)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
WINRT_EXPORT namespace winrt::Windows::UI::Xaml::Hosting
{
    inline auto ElementCompositionPreview::GetElementVisual(winrt::Windows::UI::Xaml::UIElement const& element)
    {
        return impl::call_factory<ElementCompositionPreview, IElementCompositionPreviewStatics>([&](IElementCompositionPreviewStatics const& f) { return f.GetElementVisual(element); });
    }
    inline auto ElementCompositionPreview::GetElementChildVisual(winrt::Windows::UI::Xaml::UIElement const& element)
    {
        return impl::call_factory<ElementCompositionPreview, IElementCompositionPreviewStatics>([&](IElementCompositionPreviewStatics const& f) { return f.GetElementChildVisual(element); });
    }
    inline auto ElementCompositionPreview::SetElementChildVisual(winrt::Windows::UI::Xaml::UIElement const& element, winrt::Windows::UI::Composition::Visual const& visual)
    {
        impl::call_factory<ElementCompositionPreview, IElementCompositionPreviewStatics>([&](IElementCompositionPreviewStatics const& f) { return f.SetElementChildVisual(element, visual); });
    }
    inline auto ElementCompositionPreview::GetScrollViewerManipulationPropertySet(winrt::Windows::UI::Xaml::Controls::ScrollViewer const& scrollViewer)
    {
        return impl::call_factory<ElementCompositionPreview, IElementCompositionPreviewStatics>([&](IElementCompositionPreviewStatics const& f) { return f.GetScrollViewerManipulationPropertySet(scrollViewer); });
    }
    inline auto ElementCompositionPreview::SetImplicitShowAnimation(winrt::Windows::UI::Xaml::UIElement const& element, winrt::Windows::UI::Composition::ICompositionAnimationBase const& animation)
    {
        impl::call_factory<ElementCompositionPreview, IElementCompositionPreviewStatics2>([&](IElementCompositionPreviewStatics2 const& f) { return f.SetImplicitShowAnimation(element, animation); });
    }
    inline auto ElementCompositionPreview::SetImplicitHideAnimation(winrt::Windows::UI::Xaml::UIElement const& element, winrt::Windows::UI::Composition::ICompositionAnimationBase const& animation)
    {
        impl::call_factory<ElementCompositionPreview, IElementCompositionPreviewStatics2>([&](IElementCompositionPreviewStatics2 const& f) { return f.SetImplicitHideAnimation(element, animation); });
    }
    inline auto ElementCompositionPreview::SetIsTranslationEnabled(winrt::Windows::UI::Xaml::UIElement const& element, bool value)
    {
        impl::call_factory<ElementCompositionPreview, IElementCompositionPreviewStatics2>([&](IElementCompositionPreviewStatics2 const& f) { return f.SetIsTranslationEnabled(element, value); });
    }
    inline auto ElementCompositionPreview::GetPointerPositionPropertySet(winrt::Windows::UI::Xaml::UIElement const& targetElement)
    {
        return impl::call_factory<ElementCompositionPreview, IElementCompositionPreviewStatics2>([&](IElementCompositionPreviewStatics2 const& f) { return f.GetPointerPositionPropertySet(targetElement); });
    }
    inline auto ElementCompositionPreview::SetAppWindowContent(winrt::Windows::UI::WindowManagement::AppWindow const& appWindow, winrt::Windows::UI::Xaml::UIElement const& xamlContent)
    {
        impl::call_factory<ElementCompositionPreview, IElementCompositionPreviewStatics3>([&](IElementCompositionPreviewStatics3 const& f) { return f.SetAppWindowContent(appWindow, xamlContent); });
    }
    inline auto ElementCompositionPreview::GetAppWindowContent(winrt::Windows::UI::WindowManagement::AppWindow const& appWindow)
    {
        return impl::call_factory<ElementCompositionPreview, IElementCompositionPreviewStatics3>([&](IElementCompositionPreviewStatics3 const& f) { return f.GetAppWindowContent(appWindow); });
    }
}
namespace std
{
#ifndef WINRT_LEAN_AND_MEAN
    template<> struct hash<winrt::Windows::UI::Xaml::Hosting::IElementCompositionPreview> : winrt::impl::hash_base {};
    template<> struct hash<winrt::Windows::UI::Xaml::Hosting::IElementCompositionPreviewStatics> : winrt::impl::hash_base {};
    template<> struct hash<winrt::Windows::UI::Xaml::Hosting::IElementCompositionPreviewStatics2> : winrt::impl::hash_base {};
    template<> struct hash<winrt::Windows::UI::Xaml::Hosting::IElementCompositionPreviewStatics3> : winrt::impl::hash_base {};
    template<> struct hash<winrt::Windows::UI::Xaml::Hosting::ElementCompositionPreview> : winrt::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
