//
// Created by Sixik on 12.12.2025.
//
#ifndef NOESIS_JNI_JAVANOTIFYPROPERTYCHANGEDBASE_H
#define NOESIS_JNI_JAVANOTIFYPROPERTYCHANGEDBASE_H

#include "App/ApplicationLauncher/Include/NsApp/NotifyPropertyChangedBase.h"

namespace NoesisJava {
    class JavaNotifyPropertyChangedBase : public NoesisApp::NotifyPropertyChangedBase {
    public:
        JavaNotifyPropertyChangedBase() = default;

        void JavaOnPropertyChanged(const char* name) {
            OnPropertyChanged(name);
        }
    };
}
#endif //NOESIS_JNI_JAVANOTIFYPROPERTYCHANGEDBASE_H