#pragma once

#include <borealis.hpp>

class InstallTab : public brls::Box {
  public:
    InstallTab();

    static brls::View* create();

  private:
    BRLS_BIND(brls::Label, progress, "progress");
    BRLS_BIND(brls::Slider, slider, "slider");
    bool onInstallButtonClicked(brls::View* view);
};
