/* *******************************************************************************************
 * Samael.Raven.c - Samael.Raven is the central hub for all network and communication
 * functionalities within the Samael framework. Inspired by the role of ravens as messengers in
 * mythology, it seamlessly handles email operations, internet connectivity, and general data
 * transmission. This module supports composing, sending, and receiving emails, while also
 * enabling HTTP/HTTPS requests and interactions with APIs. Samael.Raven is designed to manage
 * secure network communications, incorporating encryption and authentication for reliable data
 * exchange. With tools for handling notifications, monitoring network activity, and debugging,
 * it ensures optimized performance and functionality. Its versatility makes it an indispensable
 * component for establishing and maintaining robust communication pipelines. Samael.Raven
 * bridges the digital divide, embodying the efficiency and reliability of a modern-day messenger
 * in the digital world.
 * -------------------------------------------------------------------------------------------
 * Author:  Patrik Eigenmann
 * eMail:   p.eigenmann@gmx.net
 * GitHub:  www.github.com/PatrikEigenmann/cpp
 * -------------------------------------------------------------------------------------------
 * Wed 2025-03-26 File created.                                                 Version: 00.01
 * Sun 2025-04-06 Register package Raven with it's version number.              Version: 00.02
 * Mon 2025-04-07 Implemented the Samael naming convention.                     Version: 00.03
 * Tue 2025-04-08 BugFix: RegisterVersion("Samael.Raven", "", 0, 4);            Version: 00.04
 * ********************************************************************************************/

#include "Samael.h"
#include "Samael.Raven.h"

// -------------------------------------------------------------------------------------------
// RegRaven - Automatically registers this component's version information with the versioning
// system of the Samael framework.
//
// This function is marked with the constructor attribute in the implementation file
// (Samael.Raven.c), which means it will automatically be executed prior to the execution
// of the main() function. This pre-main invocation is part of the automatic versioning
// mechanism, ensuring that the version details for this component are registered as soon
// as the module is loaded.
// -------------------------------------------------------------------------------------------
__attribute__((constructor)) void RegRaven(void) {
    // Register the Raven package with its version number.
    RegisterVersion("Samael.Raven", "", 0, 4);
}