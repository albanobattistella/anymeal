SUFFIXES = .ui .cc .hh .ll

bin_PROGRAMS = anymeal

noinst_LIBRARIES = libanymeal.a

noinst_HEADERS = main_window.hh partition.hh mealmaster.hh recipe.hh ingredient.hh

EXTRA_DIST = main_window.ui

BUILT_SOURCES = ui_main_window.hh moc_main_window.cc

anymeal_SOURCES = anymeal.cc main_window.cc moc_main_window.cc
anymeal_CXXFLAGS = $(QT_CXXFLAGS)
anymeal_LDFLAGS =
anymeal_LDADD = libanymeal.a $(QT_LIBS)

libanymeal_a_SOURCES =  partition.cc recipe.cc ingredient.cc mealmaster.ll
libanymeal_a_CXXFLAGS =
libanymeal_a_LIBADD =

ui_%.hh: %.ui
	$(QT_UIC) -o $@ $<

moc_%.cc: %.hh
	$(QT_MOC) -o $@ $<