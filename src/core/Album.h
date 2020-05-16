#ifndef ALBUM_H
#define ALBUM_H

#include <iostream>
#include <string>
#include <QString>

class Album {
 public:
  explicit Album(const QString& name = "");
  int id() const;
  void setId(int id);
  QString name() const;
  void setName(const QString& name);

 private:
  int mId{-1};
  QString mName;
};

#endif  // ALBUM_H
