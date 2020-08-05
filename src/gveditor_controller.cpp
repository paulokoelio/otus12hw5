#include "gveditor_controller.h"
#include "gveditor_basefncl.h"
#include "gveditor_coord2d.h"
#include "gveditor_shapes.h"
#include "version.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

namespace gvedt
{
void controller::init(const int argc, char const **argv)
{
    if (gvedt::controller::ref().init_good == true) return;
    if (argc > 1)
    {
        if (std::string(argv[1]) == std::string("version"))
        {
            std::cout << "Version of gveditor is " << gvedt::version() << std::endl;
            gvedt::controller::ref().exit = true;
        }
        else
        {
            //\todo: Try to open file with name in argv[1]
        }
    }
    
    if (gvedt::controller::ref().exit == true) return;

    gvedt::controller::ref().init_good = true;
}

void controller::init_gui(std::shared_ptr<igui> spgui)
{
    sp_gui = spgui;
    sp_main_window = sp_gui->new_mainwindow(MAIN_WINDOW_SIZE, MAIN_WINDOW_NAME);
    // здесь загружается перечень меню и другие ресурсы gui методом,
    // предусмотренным конкретным типом gui
}

std::shared_ptr<igui> controller::get_gui()
{
    return sp_gui;
}

bool controller::app_exit() const { return gvedt::controller::ref().exit; }

void controller::close_app()
{
    exit = true;
}

void controller::new_document(std::string document_name)
{
    if (!sp_doc_window) sp_doc_window = gvedt::controller::ref().get_gui()->new_window(DOC_WINDOW_SIZE, document_name);
    // Далее здесь логика создания нового документа
    sp_doc = slvr::lib::factory<gvedt::doc>();
    sp_object.reset();
}

void controller::import_file()
{
    if (sp_doc_window) sp_gui->close(sp_doc_window->handle);
    gvedt::controller::ref().new_document(std::string("importing_file"));
    context_text[0] = std::string("Please choose file to import ");
    sp_gui->get_filename(context_text[1], context_text[0]);
    std::filesystem::path file_imp{context_text.at(1)};
    if (!(std::filesystem::exists(file_imp)  && file_imp.has_filename() ))
    {
        // Обработка ситуации, когда gui предоставляет некорректное/недоступное имя файла
        return;
    }
    std::ifstream file_imp_stream(file_imp.native(), std::ios::in | std::ios::binary);
    if (!file_imp_stream)
    {
        // Обработка ситуации при ошибке открытия файла
        return;
    }

    try
    {
        file_imp_stream >> *sp_doc;
    }
    catch (const std::exception &e)
    {
        // Обработка ситуации при ошибке считывания файла (ошибке формата и др.)
    }
    this->refresh_doc_window();
}

void controller::export_file()
{
    // Реализация процедуры аналогична import_file(), с учетом 
    // записи документа в файл с помощью operator<< и std::ofstream
}

void controller::new_shape(gvedt::obj_types shape_type)
{
    if (!gvedt::controller::ref().sp_doc_window) return;
    sp_object = shape_factory(shape_type);
    sp_doc->add_shape(sp_object);
    // Получение из GUI координат точек и других данных фигуры, например, так:
    context_data = sp_gui->build_shape(sp_object);
    sp_object->create(context_data);
}

void controller::delete_shape()
{
    // GUI должно удалить изображение фигуры до вызова этого метода
    if (!sp_object) return;
    sp_doc->delete_shape(sp_object->get_id());
    sp_object.reset();
}

void controller::select_shape(int id)
{
    sp_object = sp_doc->get_shape(id);
}

void controller::refresh_doc_window()
{
    // Очищение окна документа и полное отображение содержимого текущего документа в окне
}

} // namespace gvedt
