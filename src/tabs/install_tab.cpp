#include "tabs/install_tab.hpp"

InstallTab::InstallTab() {
    this->inflateFromXMLRes("xml/tabs/install.xml");

    BRLS_REGISTER_CLICK_BY_ID("install_button", this->onInstallButtonClicked);
}

int selected = 0;
bool InstallTab::onInstallButtonClicked(brls::View* view) {
    // TODO
    return true;
}

brls::View* InstallTab::create() { return new InstallTab(); }
