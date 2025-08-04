#pragma once

#include <string>
#include <vector>

#ifdef AUTHMANAGER_EXPORTS
#define AUTHMANAGER_API __declspec(dllexport)
#else
#define AUTHMANAGER_API __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C" {
#endif

// Configuration
AUTHMANAGER_API void AuthManager_SetConfig(const char* appName, const char* ownerId, const char* appSecret);

// Core authentication functions
AUTHMANAGER_API bool AuthManager_CheckAppExists(const char* appName, const char* ownerId, const char* appSecret);
AUTHMANAGER_API bool AuthManager_CheckUserExists(const char* username, const char* password, const char* ownerId);
AUTHMANAGER_API bool AuthManager_CheckLicense(const char* license, const char* hwid, const char* ownerId);
AUTHMANAGER_API bool AuthManager_RegisterUser(const char* username, const char* password, const char* license, const char* hwid, const char* ownerId);

// Utility functions
AUTHMANAGER_API bool AuthManager_ValidateInput(const char* username, const char* password);
AUTHMANAGER_API const char* AuthManager_GetHWID();

// Authentication interface
AUTHMANAGER_API bool AuthManager_Login();
AUTHMANAGER_API bool AuthManager_License();
AUTHMANAGER_API bool AuthManager_Register();

// Interface functions for client applications
AUTHMANAGER_API bool AuthManager_LoginInterface();
AUTHMANAGER_API bool AuthManager_LicenseInterface();
AUTHMANAGER_API bool AuthManager_RegisterInterface();

#ifdef __cplusplus
}
#endif