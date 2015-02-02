%define _topdir /home/rpmbuild/
%define name test
%define release 1
%define version 1.0
%define  buildroot %{_topdir}/%{name}-%{version}-root

BuildRoot: %{buildroot}
Summary: GNU Test RPM
License: GPL
Name: %{name}
Version: %{version}
Release: %{release}
Source: %{name}-%{version}.tar.gz
prefix: /usr
Group: Development/Tools 

%description
Test RPM 

%prep
%setup -q
make
      
%build
make
    
    
%install
rm -rf $RPM_BUILD_ROOT
install -d $RPM_BUILD_ROOT/opt/test-1.0/
install Makefile $RPM_BUILD_ROOT/opt/test-1.0/Makefile
install README $RPM_BUILD_ROOT/opt/test-1.0/README
install test.c $RPM_BUILD_ROOT/opt/test-1.0/test.c

%clean
rm -rf $RPM_BUILD_ROOT
%files
%defattr(-,root,root,-)
/opt/test-1.0/*

%post
chmod 755 -R /opt/test-1.0



