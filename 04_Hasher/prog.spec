Name:           prog
Version:        0.0.1
Release:        alt1
Group:          Other
License:        MIT
URL:            https://github.com/ioccc-src/winner/blob/master/2025/kurdyukov/
Source:         %name-%version.tar.gz
Summary:        Demo for hasher

BuildRequires:  make

%description
How many arithmetic ways can we form numbers out of other numbers? The answer is a great deal. But to find the shortest mathematical expression: that is more of a challenge. To do that in only 1196 bytes of C code: that is impressive!

%prep
%setup -c

%build
cd kurdyukov
make %name

%install
cd kurdyukov
install -D %name %buildroot/%_bindir/%name

%files
%_bindir/%name
%doc kurdyukov/README.md

