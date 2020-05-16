#ifndef PICTURE_H
#define PICTURE_H

#include <QString>
#include <QUrl>
#include <iostream>

class Picture {
 public:
  explicit Picture(const QString& filePath = "");
  explicit Picture(const QUrl& fileUrl);

  int id() const;
  void setId(int id);

  int albumId() const;
  void setAlbumId(int albumId);

  QUrl fileUrl() const;
  void setFileUrl(const QUrl& fileUrl);

 private:
  int mId{-1};
  int mAlbumId{-1};
  QUrl mFileUrl;
};

#endif  // PICTURE_H
