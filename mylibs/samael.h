/* *******************************************************************************************
 * Samael.h - Samael is a developer’s answer to complexity, built on the philosophy that clarity,
 * transparency, and functionality should take precedence over unnecessary complications. It
 * redefines how applications are structured by focusing on flexibility, scalability, and
 * effortless integration, allowing developers to cut through inefficiencies and focus entirely on
 * what matters—execution without obstacles.
 * 
 * Just as the archangel Samael was misunderstood, this framework challenges conventional development
 * processes by simplifying methodologies while preserving power and precision. Samael’s black-box
 * approach enables rapid adoption, reducing development overhead while ensuring robust, adaptable
 * solutions that scale across applications of all sizes.
 * 
 * Instead of restrictive workflows, Samael offers intelligent automation, intuitive design, and a
 * streamlined development experience, allowing ideas to become functional realities with minimal
 * effort. It eliminates unnecessary friction, making software creation more efficient, more precise,
 * and undeniably effective. The underrated foundation of modern application architecture—Samael
 * is development without compromise.
 * 
 * Compiler instructions:
 * gcc -shared -o bin/libSamael.so Samael.c ToolBox/cManPage.c ToolBox/cProgress.c
 *        ToolBox/cVersion.c TowerOfBabel/rotor.c TowerOfBabel/enigma.c
 * or pmake Samael.makefile
 * -------------------------------------------------------------------------------------------
 * Author:  Patrik Eigenmann
 * eMail:   p.eigenmann@gmx.net
 * GitHub:  www.github.com/PatrikEigenmann/cpp
 * -------------------------------------------------------------------------------------------
 * Change log:
 * Sat 2025-03-22 File created.                                                 Version: 00.01
 * Sun 2025-03-23 Folder update: From util to utility.                          Version: 00.02
 * Wed 2025-03-25 Folder update: From Utility to ToolBox.                       Version: 00.03
 * Wed 2025-03-26 Path correction for Windows/Unix systems.                     Version: 00.04
 * Thu 2025-03-27 Include all the modules for the Samael Framework.             Version: 00.05
 * Sun 2025-04-06 Register the Samael framework with it's version number.       Version: 00.06
 * ********************************************************************************************/
#ifndef SAMAEL_H
#define SAMAEL_H

// -------------------------------------------------------------------------------------------
// Include all Framework headers.
// -------------------------------------------------------------------------------------------
#include "Samael.Alchemy.h"
#include "Samael.Chronicle.h"
#include "Samael.Entanglement.h"
#include "Samael.HuginAndMunin.h"
#include "Samael.Necronomicon.h"
#include "Samael.Raven.h"
#include "Samael.Scribe.h"
#include "Samael.Tabernacle.h"
#include "Samael.ToolBox.h"
#include "Samael.TowerOfBabel.h"

#include "Framework.h"

// -------------------------------------------------------------------------------------------
// regSamael - Automatically registers this component's version information with the versioning
// system of the Samael framework.
//
// This function is marked with the constructor attribute in the implementation file
// (Samael.c), which means it will automatically be executed prior to the execution
// of the main() function. This pre-main invocation is part of the automatic versioning
// mechanism, ensuring that the version details for this component are registered as soon
// as the module is loaded.
// -------------------------------------------------------------------------------------------
void regSamael(void);

#endif