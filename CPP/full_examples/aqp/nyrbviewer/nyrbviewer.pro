CONFIG	    += console debug
QT	    += network webkit
HEADERS	    += ../aqp/kuhn_munkres.hpp
SOURCES	    += ../aqp/kuhn_munkres.cpp
HEADERS	    += ../aqp/alt_key.hpp
SOURCES	    += ../aqp/alt_key.cpp
HEADERS	    += ../aqp/aqp.hpp
SOURCES	    += ../aqp/aqp.cpp
INCLUDEPATH += ../aqp
HEADERS     += ../browserwindow/browserwindow.hpp
SOURCES     += ../browserwindow/browserwindow.cpp
RESOURCES   += ../browserwindow/browserwindow.qrc
INCLUDEPATH += ../browserwindow
HEADERS	    += ../option_parser/option_parser.hpp
SOURCES	    += ../option_parser/option_parser.cpp
INCLUDEPATH += ../option_parser
HEADERS     += linkfetcher.hpp
SOURCES     += linkfetcher.cpp
HEADERS     += mainwindow.hpp
SOURCES     += mainwindow.cpp
SOURCES     += main.cpp
RESOURCES   += nyrbviewer.qrc
