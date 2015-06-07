#include <QtDesigner/customwidget>

class IconEditorPlugin : public QObject, public QDesignerCustomWidgetInterface
{
    Q_OBJECT
    Q_INTERFACES(QDesignerCustomWidgetInterface)

public:
    IconEditorPlugin(QObject *parent = 0);

    QString name() const;
    QString includeFile() const;
    QString group() const;
    QIcon icon() const;
    QString toolTip() const;
    QString whatsThis() const;
    bool isContainer() const;
    QWidget *createWidget(QWidget *parent);
};

IconEditorPlugin::IconEditorPlugin(QObject *parent) : QObject(parent)
{
}

QString IconEditorPlugin::name() const
{
    return "IconEditor";
}

QString IconEditorPlugin::includeFile() const
{
    return "iconeditor.h";
}

QString IconEditorPlugin::group() const
{
    return tr("Image Manipulation Widgets");
}

QIcon IconEditorPlugin::icon() const
{
    return QIcon(":/icon.png");
}

QString IconEditorPlugin::toolTip() const
{
    return tr("An icon editor widget");
}

QString IconEditorPlugin::whatsThis() const
{
    return tr("This widget is from a lesson on Qt ");
}

bool IconEditorPlugin::isContainer() const
{
    return false;
}

QWidget *IconEditorPlugin::createWidget(QWidget *parent)
{
    return new IconEditor(parent);
}

Q_EXPORT_PLUGIN2(iconeditorplugin, IconEditorPlugin)
