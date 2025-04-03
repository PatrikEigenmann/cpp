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
 * ********************************************************************************************/
#ifndef SAMAEL_H
#define SAMAEL_H

/* *******************************************************************************************
 * Include all Alchemy headers: Samael.Alchemy is designed to transform the fundamental
 * elements of mathematics into powerful tools for solving complex problems. It provides a rich
 * suite of operations, from basic calculations to advanced equation solving and symbolic
 * manipulation. This module is built to handle numerical data with precision and supports
 * seamless integration into larger workflows. With its intuitive interface, Samael.Alchemy
 * aims to simplify mathematical processes while maintaining flexibility for intricate
 * computations. It empowers developers and users to derive insights, optimize algorithms,
 * and explore mathematical patterns effectively. Whether applied to scientific research,
 * engineering tasks, or financial analysis, Samael.Alchemy is the cornerstone for mathematical
 * mastery within the Samael framework. Its ability to make abstract mathematical concepts
 * actionable and accessible ensures it remains an indispensable resource.
 * ********************************************************************************************/
#include "Samael.Alchemy.h"

/* *******************************************************************************************
 * Include all Chronicle headers: Samael.Chronicle serves as the guardian of history,
 * preserving the evolution and progression of a project through meticulous version control.
 * It offers a robust suite of tools to track changes, manage revisions, and maintain the
 * integrity of development workflows. Designed with precision, this module ensures that every
 * iteration is documented and easily retrievable for reference or rollback. Samael.Chronicle
 * emphasizes collaboration and transparency, enabling seamless integration across team
 * environments. By maintaining a comprehensive record of transformations, it provides clarity
 * and insight into the development process. Whether for individual projects or large-scale
 * initiatives, this module safeguards the legacy of code while empowering developers to move
 * forward with confidence. Samael.Chronicle stands as a testament to the importance of 
 * preserving progress and celebrating innovation.
 * ********************************************************************************************/
#include "Samael.Chronicle.h"

/* *******************************************************************************************
 * Include all Entanglement headers: Samael.Entanglement is a module dedicated to mastering
 * the intricate world of array and list operations. It provides a comprehensive suite of tools
 * for sorting, searching, and manipulating data structures with precision and efficiency.
 * Designed for versatility, it seamlessly integrates with other modules while maintaining
 * independent robustness. Samael.Entanglement emphasizes performance optimization, ensuring
 * that even the most complex operations are handled swiftly and effectively. Its capabilities
 * extend beyond basic utilities, enabling developers to implement sophisticated algorithms like
 * quicksort or quickfind with ease. Whether tackling large datasets or intricate data
 * relationships, this module empowers users to untangle complexity and find clarity.
 * Samael.Entanglement brings order to chaos, transforming raw collections into structured,
 * actionable insights.
 * ********************************************************************************************/
#include "Samael.Entanglement.h"

/* *******************************************************************************************
 * Include all HuginAndMunin headers: Samael.HuginAndMunin is the essential module for managing
 * logging and messaging within the Samael framework. Named after Odin's legendary ravens, it
 * symbolizes the flow of thought and memory, embodying the transmission and preservation of
 * vital information. This module handles both real-time communication and long-term logging
 * with precision and reliability. Samael.HuginAndMunin ensures that every message is delivered
 * accurately and every log entry is stored for reference and analysis. Its versatile design
 * supports integration with other modules and external systems, making it adaptable for a wide
 * range of use cases. From debugging to data pipelines, this module provides the infrastructure
 * needed for seamless information flow. Samael.HuginAndMunin bridges the past and present,
 * capturing the narrative of events and enabling insightful decision-making.
 * ********************************************************************************************/
#include "Samael.HuginAndMunin.h"

/* *******************************************************************************************
 * Include all Necronomicon headers: Samael.Necronomicon stands as the ultimate repository for
 * powerful and arcane knowledge in the realm of databases. This module seamlessly handles
 * connectivity, storage, and analytics for systems like SQLite, MySQL, and Progress, offering
 * both flexibility and reliability. Samael.Necronomicon is designed to simplify complex database
 * interactions, making it effortless to query, manage, and analyze data. With its intuitive
 * interface, it empowers developers to uncover insights and optimize workflows. From handling
 * vast datasets to ensuring secure connections, this module provides a robust foundation for
 * all database-related tasks. Samael.Necronomicon bridges the gap between raw data and meaningful
 * results, embodying the mystical transformation of information into wisdom. By harnessing its
 * capabilities, users can command their databases with confidence and precision.
 * ********************************************************************************************/
#include "Samael.Necronomicon.h"

/* *******************************************************************************************
 * Include all Raven headers: Samael.Raven is the central hub for all network and communication
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
 * ********************************************************************************************/
#include "Samael.Raven.h"

/* *******************************************************************************************
 * Include all Scribe headers: Samael.Scribe is the dedicated module for handling file operations
 * within the Samael framework. Its purpose is to streamline tasks such as reading, writing, and
 * managing files with efficiency and precision. Samael.Scribe provides a robust toolkit for
 * working with various file types and structures, ensuring compatibility across diverse use
 * cases. The module is designed to simplify complex file operations, offering intuitive methods
 * for seamless integration into larger workflows. It also emphasizes data integrity, ensuring
 * that files are handled safely and reliably. Whether creating, organizing, or modifying files,
 * Samael.Scribe serves as a reliable assistant in managing the written artifacts of any
 * application. Its versatility and reliability make it an indispensable element of the
 * framework.
 * ********************************************************************************************/
#include "Samael.Scribe.h"

/* *******************************************************************************************
 * Include all Tabernacle headers: Samael.Tabernacle serves as a sanctuary for configuration
 * and settings management within the Samael framework. It provides a centralized and structured
 * approach to storing and retrieving application configurations, ensuring consistency and ease
 * of use. Samael.Tabernacle is designed to handle both static and dynamic settings, accommodating
 * everything from simple key-value pairs to complex hierarchical structures. This module supports
 * seamless integration with external configuration files and environment variables, adapting to
 * various deployment scenarios. It emphasizes flexibility and clarity, allowing for
 * straightforward customization and runtime adjustments. Whether used for managing global
 * parameters, user preferences, or environment-specific settings, Samael.Tabernacle ensures
 * that every detail is organized and accessible. It acts as the cornerstone of stability and
 * adaptability, safeguarding the integrity of application configurations.
 * ********************************************************************************************/
#include "Samael.Tabernacle.h"

/* *******************************************************************************************
 * Include all ToolBox headers: Samael.ToolBox is the foundational module for practical and
 * essential utilities within the Samael framework. It serves as a centralized repository for
 * frequently used tools, offering streamlined methods to perform common tasks such as type
 * checks, validations, and basic operations. This module is intentionally general-purpose,
 * providing accessible and efficient solutions for handling routine programming needs.
 * Samael.ToolBox ensures that developers can rely on a consistent set of functions to simplify
 * their workflows without duplicating efforts across different modules. Its lightweight design
 * prioritizes adaptability, making it easy to integrate into a wide range of applications.
 * From basic operations to sophisticated utilities, Samael.ToolBox embodies versatility and
 * efficiency, supporting both the framework and its extensions. It stands as a reliable
 * companion for developers seeking clarity and simplicity in their codebase.
 * ********************************************************************************************/
#include "Samael.ToolBox.h"

/* *******************************************************************************************
 * Include all TowerOfBabel headers: Samael.TowerOfBabel is the cryptography module within the
 * Samael framework, offering a comprehensive set of tools for encryption, decryption, and
 * secure data processing. It is designed to handle diverse methods and techniques, enabling
 * robust protection and transformation of information across various contexts. This module
 * emphasizes adaptability, supporting a wide range of encryption use cases, from simple encoding
 * tasks to advanced security implementations. Samael.TowerOfBabel prioritizes reliability and
 * flexibility, ensuring seamless integration into both modern and legacy systems. Its structured
 * approach allows developers to implement secure and efficient workflows while maintaining
 * clarity and control. Whether for securing data, facilitating private communication, or
 * exploring cryptographic concepts, this module serves as an essential resource for safeguarding
 * information within the framework.
 * ********************************************************************************************/
#include "Samael.TowerOfBabel.h"

#endif