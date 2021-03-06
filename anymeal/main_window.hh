/* AnyMeal recipe database software
   Copyright (C) 2020 Jan Wedekind

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>. */
#pragma once
#include <vector>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QCompleter>
#include <QtPrintSupport/QPrinter>
#include "ui_main_window.hh"
#include "database.hh"
#include "titles_model.hh"
#include "categories_model.hh"


class gui_exception: public std::exception
{
public:
  gui_exception(const std::string &error): m_error(error) {}
  virtual const char *what(void) const throw() { return m_error.c_str(); }
protected:
  std::string m_error;
};

class MainWindow: public QMainWindow
{
  Q_OBJECT
public:
  MainWindow(QWidget *parent=nullptr);
  static std::string translate(const char *context, const char *text);
  std::vector<sqlite3_int64> recipe_ids(void);
public slots:
  void import(void);
  void edit(void);
  void about(void);
  void filter(void);
  void reset(void);
  void selected(const QModelIndex &current, const QModelIndex &previous);
  void titles_context_menu(const QPoint &pos);
  void recipe_context_menu(const QPoint &pos);
  void export_recipes(void);
  void delete_recipes(void);
  void preview(void);
  void print(void);
  void render(QPrinter *printer);
protected:
  Ui::MainWindow m_ui;
  Database m_database;
  TitlesModel *m_titles_model;
  CategoriesModel *m_categories_model;
  QCompleter *m_categories_completer;
  QMenu *m_titles_context_menu;
  QMenu *m_recipe_context_menu;
};
