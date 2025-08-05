# AuthManager CSharp (C#) Library

A native C++ authentication library with C# wrapper for user management, licensing and authentication.

## Features

- **Username/password authentication**
- **License authentication**
- **User registration**
- **Application validation**
- **Automatic HWID generation**
- **Integrated user interface**
- **Windows Forms and Console support**

## Project Structure

```
CSharp-Library/
├── AuthManager.h           # C++ library header
├── CSharp-Library.cpp      # Library implementation
└── CSharp-Library.dll      # Compiled library
```

## Installation

1. Compile the C++ library or use the provided DLL
2. Copy `CSharp-Library.dll` to your project
3. Add `AuthManagerWrapper.cs` to your project
4. Configure your project to use Windows Forms (if necessary)

## Usage

### Initial Configuration

```csharp
// Library configuration
string app_name = "YOUR_APP_NAME";
string ownerid = "YOUR_OWNER_ID";
string app_secret = "YOUR_APP_SECRET";

AuthManagerWrapper.AuthManager_SetConfig(app_name, ownerid, app_secret);

// Check application existence
if (!AuthManagerWrapper.AuthManager_CheckAppExists(app_name, ownerid, app_secret))
{
    Console.WriteLine("Application not found");
    return;
}
```

### Simple Authentication

```csharp
// Login with integrated interface
if (AuthManagerWrapper.AuthManager_LoginInterface())
{
    Console.WriteLine("Login successful!");
}

// License validation with integrated interface
if (AuthManagerWrapper.AuthManager_LicenseInterface())
{
    Console.WriteLine("Valid license!");
}

// Registration with integrated interface
if (AuthManagerWrapper.AuthManager_RegisterInterface())
{
    Console.WriteLine("Registration successful!");
}
```

### Manual Authentication

```csharp
// User verification
string username = "user";
string password = "password";
if (AuthManagerWrapper.AuthManager_CheckUserExists(username, password, ownerid))
{
    Console.WriteLine("Valid user");
}

// License verification
string license = "YOUR-LICENSE";
string hwid = AuthManagerWrapper.GetHWID();
if (AuthManagerWrapper.AuthManager_CheckLicense(license, hwid, ownerid))
{
    Console.WriteLine("Valid license");
}

// User registration
if (AuthManagerWrapper.AuthManager_RegisterUser(username, password, license, hwid, ownerid))
{
    Console.WriteLine("User registered");
}
```

## Application Examples

### Console Application (CSharp-Console)

Simple console application with interactive menu:
- Username/password login
- License login
- User registration
- Command line interface

### Windows Forms Application (CSharp-Example)

Application with graphical interface:
- Authentication form
- Buttons for each authentication type
- Error and success messages
- Modern user interface

## Project Configuration

### For Console Application

```xml
<Project Sdk="Microsoft.NET.Sdk">
  <PropertyGroup>
    <OutputType>Exe</OutputType>
    <TargetFramework>net8.0</TargetFramework>
    <ImplicitUsings>enable</ImplicitUsings>
    <Nullable>enable</Nullable>
  </PropertyGroup>
</Project>
```

### For Windows Forms Application

```xml
<Project Sdk="Microsoft.NET.Sdk">
  <PropertyGroup>
    <OutputType>WinExe</OutputType>
    <TargetFramework>net8.0-windows</TargetFramework>
    <UseWindowsForms>true</UseWindowsForms>
    <ImplicitUsings>enable</ImplicitUsings>
    <Nullable>enable</Nullable>
  </PropertyGroup>
  <ItemGroup>
    <PackageReference Include="System.Management" Version="8.0.0" />
  </ItemGroup>
</Project>
```

## API Reference

### Configuration Functions
- `AuthManager_SetConfig(appName, ownerId, appSecret)` - Configure the library
- `AuthManager_CheckAppExists(appName, ownerId, appSecret)` - Check app existence

### Authentication Functions
- `AuthManager_CheckUserExists(username, password, ownerId)` - Verify a user
- `AuthManager_CheckLicense(license, hwid, ownerId)` - Verify a license
- `AuthManager_RegisterUser(username, password, license, hwid, ownerId)` - Register a user

### Utility Functions
- `AuthManager_GetHWID()` - Get hardware ID
- `AuthManager_ValidateInput(username, password)` - Validate inputs

### Integrated Interfaces
- `AuthManager_LoginInterface()` - Login interface
- `AuthManager_LicenseInterface()` - License interface
- `AuthManager_RegisterInterface()` - Registration interface

## Prerequisites

- .NET 6.0 or higher
- Windows (for Windows Forms)
- Visual Studio 2022 or higher
- CSharp-Library.dll in output directory

## License

See the [LICENSE](LICENSE) file for more details.

## Contributing

Contributions are welcome! Feel free to open an issue or submit a pull request.

## Support

For any questions or issues, please create an issue on the repository.