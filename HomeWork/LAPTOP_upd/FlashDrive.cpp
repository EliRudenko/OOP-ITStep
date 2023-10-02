#include "FlashDrive.h"

FlashDrive::FlashDrive() {}

FlashDrive::FlashDrive(const std::string& inputN) : flashdrive_n(inputN) {}

void FlashDrive::set_flashdrive_n(const std::string& inputN) { flashdrive_n = inputN; }

const std::string& FlashDrive::get_flashdrive_n() const { return flashdrive_n; }

FlashDrive::~FlashDrive() {}
