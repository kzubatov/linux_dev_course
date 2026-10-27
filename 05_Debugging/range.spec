Name:           range
Version:        0.0.1
Release:        alt1
Group:          Other
License:        MIT
URL:            https://github.com/kzubatov/linux_dev_course/tree/master/05_Debugging
Source:         %name-%version.tar.gz
Summary:        Simple python-like range

BuildRequires:  make gcc

%description
Print an arithmetic progression, one number per line, like Python's range().

%prep
%setup

%build
make range

%install
make DESTDIR=%buildroot BIN=%_bindir install

%files
%_bindir/%name

%changelog
* Tue Oct 27 2026 kzubatov <zubatovks@mail.ru> 0.0.1-alt1
- Initial and final release

