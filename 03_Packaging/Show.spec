Name:           Show
Version:        0.0.1
Release:        alt1
Group:          Other
License:        MIT
URL:            https://https://github.com/kzubatov/linux_dev_course/tree/master/03_Packaging
Source:         %name-%version.tar.gz
Summary:        File viewer

BuildRequires:  libncurses-devel libncursesw-devel make

%description
File viewer (minimalistic)
Used for LecturesCMC/LinuxApplicationDevelopment2026/03_Packaging.

%prep
%setup -c

%build
make %name

%install
make DESTDIR=%buildroot BIN=%_bindir install

%files
%_bindir/*

