#include "Picture.h"

Picture::Picture(const QString& filePath)
    : Picture(QUrl::fromLocalFile(filePath)) {
  std::cout << "Picture created from QString" << std::endl;
}

Picture::Picture(const QUrl& fileUrl) : mFileUrl(fileUrl) {
  std::cout << "Picture created from QUrl" << std::endl;
}

int Picture::id() const {
  return mId;
}

void Picture::setId(int id) {
  mId = id;
}

int Picture::albumId() const {
  return mAlbumId;
}
void Picture::setAlbumId(int albumId) {
  mAlbumId = albumId;
}
QUrl Picture::fileUrl() const {
  return mFileUrl;
}
void Picture::setFileUrl(const QUrl& fileUrl) {
  mFileUrl = fileUrl;
}
