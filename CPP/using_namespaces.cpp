namespace ui {
  // class ...

}
#endif // header file

int main() {
    hardware::Device d;
    ui::DeviceWidget myWidget(d);
}

// or for less typing

using hardware::Device;

int main()
{
    Device d;
    ui::DeviceWidget myWidget(d);
}

