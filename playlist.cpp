#include "playlist.h"

PlayList::PlayList(QWidget *parent) :
    QDockWidget(parent)
{
    back=false;
    this->currentMusicIndex = -1;
    this->setFloating(true);
    this->setFeatures(QDockWidget::DockWidgetMovable|QDockWidget::DockWidgetFloatable);
    this->setFixedWidth(300);
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window,QBrush(QPixmap(":/img/images/79.jpg").scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    this->setPalette(palette);
    this->tableWidgePlayListMusic =  new QTableWidget();

    //this->tableWidgePlayListMusic->setRowCount(3);
    this->tableWidgePlayListMusic->setColumnCount(4);
    QStringList headers;
    headers <<"Lrc"<<"music"<<"music full"<<"lrc Full";
    this->tableWidgePlayListMusic->setHorizontalHeaderLabels(headers);
    this->tableWidgePlayListMusic->setEditTriggers ( QAbstractItemView::NoEditTriggers );
    this->tableWidgePlayListMusic->setColumnHidden(2,true);
    this->tableWidgePlayListMusic->setColumnHidden(3,true);
    this->tableWidgePlayListMusic->setColumnWidth(0,50);
    this->tableWidgePlayListMusic->setColumnWidth(1,215);
    this->tableWidgePlayListMusic->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    this->tableWidgePlayListMovie =  new QTableWidget();
    headers.clear();
    this->tableWidgePlayListMovie->setColumnCount(4);
    headers <<"subtitle"<<"movie"<<"movie full"<<"subtitle Full";
    this->tableWidgePlayListMovie->setHorizontalHeaderLabels(headers);
    this->tableWidgePlayListMovie->setEditTriggers ( QAbstractItemView::NoEditTriggers );
    this->tableWidgePlayListMovie->setColumnHidden(2,true);
    this->tableWidgePlayListMovie->setColumnHidden(3,true);
    this->tableWidgePlayListMovie->setColumnWidth(0,70);
    this->tableWidgePlayListMovie->setColumnWidth(1,195);
    this->tableWidgePlayListMovie->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    connect(this->tableWidgePlayListMusic,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(musicDoubleClick(int,int)));
    connect(this->tableWidgePlayListMovie,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(movieDoubleClick(int,int)));

    this->tabWidgetPlayList  = new QTabWidget();
    this->tabWidgetPlayList->setStyleSheet("QTabBar::tab{font:8pt;max-width: 140px;min-width: 100px;} QTabWidget::tab-bar {alignment: center;}");

    this->tabWidgetPlayList->addTab(this->tableWidgePlayListMusic,"music");
    this->tabWidgetPlayList->addTab(this->tableWidgePlayListMovie,"movie");


    this->pushButtonAddMovie = new QPushButton("+ movie");

    this->pushButtonAddMusic = new QPushButton("+ music");
    this->pushButtonSavePlayList = new QPushButton("save");

    connect(this->pushButtonAddMusic,SIGNAL(clicked()),SLOT(addMusicSlot()));
    connect(this->pushButtonAddMovie,SIGNAL(clicked()),SLOT(addMovieSlot()));
    connect(this->pushButtonSavePlayList,SIGNAL(clicked()),SLOT(savePlayList()));


    QVBoxLayout *vBoxLayout =  new QVBoxLayout();
    QHBoxLayout *layoutTop =  new QHBoxLayout();
    QWidget      *widgeTop = new QWidget();

    layoutTop->addWidget(this->pushButtonAddMusic);
    layoutTop->addWidget(this->pushButtonAddMovie);
    layoutTop->addWidget(this->pushButtonSavePlayList);
    widgeTop->setLayout(layoutTop);
    vBoxLayout->addWidget(widgeTop);
    vBoxLayout->addWidget(this->tabWidgetPlayList);

    QWidget *back = new QWidget();
    back->setLayout(vBoxLayout);
    this->setWidget(back);
    this->setMinimumHeight(400);

    connect(this,SIGNAL(readyForwardMusic()),this,SLOT(getNextMusic()));
    connect(this,SIGNAL(readyBackMusic()),this,SLOT(getNextMusic()));
    autoLoadPlayList();

}
bool PlayList::autoLoadPlayList(void)
{
    if(!loadPlayList("default.list"))
    {
        this->currentMovieIndex = 0;
        this->currentMusicIndex = 0;
        return false;
    }
    else
        return true;
}

void PlayList::addMusicSlot(void)
{
    qDebug()<<"add music";
    QStringList fileList=QFileDialog::getOpenFileNames(this,tr("selete files to play"),"/home/sunbird/media/","Music (*.wma *.mp3)");
    if(fileList.size()<=0)
    {
        QMessageBox::information(this,tr("No Music added"),tr("No Music added!"));
        return;
    }
    QString file;
    QFileInfo fileInfo;
    QString lrcPath;
    QFileInfo lrcInfo;
    int oldTableCount = this->tableWidgePlayListMusic->rowCount();
    this->tableWidgePlayListMusic->setRowCount(fileList.count()+oldTableCount);
    foreach(file,fileList)
    {
        QTableWidgetItem *lrcIcon = new QTableWidgetItem();//
        QTableWidgetItem *lrcAbsPath = new QTableWidgetItem();//
        QTableWidgetItem *musicName = new QTableWidgetItem(fileInfo.baseName());
        QTableWidgetItem *musicAbsPath = new QTableWidgetItem(fileInfo.absoluteFilePath());

        qDebug()<<"wma-> "<<file;
        fileInfo.setFile(file);
        musicName->setText(fileInfo.baseName());
        musicAbsPath->setText(file);

        if(file.endsWith(("wma"),Qt::CaseInsensitive)){
            //qDebug()<<"wma find lrc";
            lrcIcon->setText("WMA");
            lrcIcon->setBackground(QBrush(QColor(Qt::green),Qt::SolidPattern));
            lrcPath = file.left(file.size()-3) + "lrc";
            //musicName->setIcon(QIcon(":/images/mp3.png"));
        }
        else
        {

            if(file.endsWith(("mp3"),Qt::CaseInsensitive))
            {
                //qDebug()<<"mp3 find lrc";
                lrcIcon->setText("MP3");
                lrcPath = file.left(file.size()-3) + "lrc";
                lrcAbsPath->setText(file.left(file.size()-3) + "lrc");
                //musicName->setIcon(QIcon(":/images/mp3.png"));
            }
            else
            {
                lrcIcon->setText("ERROR");
                lrcIcon->setBackground(QBrush(QColor(Qt::red),Qt::SolidPattern));
            }

        }
        lrcInfo.setFile(lrcPath);
        qDebug()<<"LRC->"<<lrcPath;
        if(lrcInfo.exists())
        {
            lrcIcon->setBackground(QBrush(QColor(Qt::green),Qt::SolidPattern));
            lrcAbsPath->setText(lrcPath);
        }
        else
            lrcIcon->setBackground(QBrush(QColor(Qt::red),Qt::SolidPattern));

        this->tableWidgePlayListMusic->setItem(oldTableCount,0,lrcIcon);
        this->tableWidgePlayListMusic->setItem(oldTableCount,1,musicName);
        this->tableWidgePlayListMusic->setItem(oldTableCount,2,musicAbsPath);
        this->tableWidgePlayListMusic->setItem(oldTableCount,3,lrcAbsPath);
        oldTableCount++;
    }


}

void PlayList::addMovieSlot(void)
{
    qDebug()<<"add movie";
    QStringList fileList=QFileDialog::getOpenFileNames(this,tr("selete files to play"),"/home/","Movie (*.flv *.mp4 *.rmvb *.avi)");
    if(fileList.size()<=0)
    {
        QMessageBox::information(this,tr("No Movie added"),tr("No Movie added!"));
        return;
    }


    QString file;
    QFileInfo fileInfo;
    QString lrcPath;
    QFileInfo lrcInfo;
    int oldTableCount = this->tableWidgePlayListMovie->rowCount();
    this->tableWidgePlayListMovie->setRowCount(fileList.count()+oldTableCount);
    foreach(file,fileList)
    {
        QTableWidgetItem *lrcIcon = new QTableWidgetItem();//
        QTableWidgetItem *lrcAbsPath = new QTableWidgetItem();//
        QTableWidgetItem *musicName = new QTableWidgetItem(fileInfo.baseName());
        QTableWidgetItem *musicAbsPath = new QTableWidgetItem(fileInfo.absoluteFilePath());

        qDebug()<<"insert file-> "<<file;
        fileInfo.setFile(file);
        musicName->setText(fileInfo.baseName());
        musicAbsPath->setText(file);

        if(file.endsWith(("mp4"),Qt::CaseInsensitive)){
            qDebug()<<"wma find mp4";
            lrcIcon->setText("MP4");
            lrcIcon->setBackground(QBrush(QColor(Qt::green),Qt::SolidPattern));
            lrcAbsPath->setText(file.left(file.size()-3) + "lrc");
            //musicName->setIcon(QIcon(":/images/mp3.png"));
        }
           else
          {

              if(file.endsWith(("rmvb"),Qt::CaseInsensitive))
             {
                //qDebug()<<"mp3 find lrc";
                lrcIcon->setText("RMVB");
                lrcIcon->setBackground(QBrush(QColor(Qt::green),Qt::SolidPattern));
                lrcAbsPath->setText(file.left(file.size()-3) + "lrc");
                //musicName->setIcon(QIcon(":/images/mp3.png"));
             }

             else
             {

                if(file.endsWith(("avi"),Qt::CaseInsensitive))
                 {
                    //qDebug()<<"mp3 find lrc";
                    lrcIcon->setText("AVI");
                    lrcIcon->setBackground(QBrush(QColor(Qt::green),Qt::SolidPattern));
                    lrcAbsPath->setText(file.left(file.size()-3) + "lrc");
                    //musicName->setIcon(QIcon(":/images/mp3.png"));
                }
                    else
                    {
                      lrcIcon->setText("ERROR");
                      lrcIcon->setBackground(QBrush(QColor(Qt::red),Qt::SolidPattern));
                    }


                }

        }

        this->tableWidgePlayListMovie->setItem(oldTableCount,0,lrcIcon);
        this->tableWidgePlayListMovie->setItem(oldTableCount,1,musicName);
        this->tableWidgePlayListMovie->setItem(oldTableCount,2,musicAbsPath);
        this->tableWidgePlayListMovie->setItem(oldTableCount,3,lrcAbsPath);
        oldTableCount++;
    }

}

void PlayList::savePlayList()
{
    this->pushButtonAddMovie->setDisabled(true);
    this->pushButtonAddMusic->setDisabled(true);
    this->pushButtonSavePlayList->setDisabled(true);
    int musicNum = this->tableWidgePlayListMusic->rowCount();
    int movieNum = this->tableWidgePlayListMovie->rowCount();
    qDebug()<<"save playlist"<<musicNum<<movieNum;


    QDomDocument *xml = new QDomDocument();
    QDomElement root = xml->createElement("fengjiaolist");
    xml->appendChild(root);
    QDomElement musicList = xml->createElement("music_list");
    musicList.setAttribute("index",this->currentMusicIndex);
    musicList.setAttribute("total",musicNum);
    root.appendChild(musicList);

    for(int i = 0;i < musicNum;i++){
        QDomElement music = xml->createElement("music");
        QDomElement musicPath = xml->createElement("music_path");
        QDomText musicPathValue =xml->createTextNode(this->tableWidgePlayListMusic->item(i,2)->text());
        musicPath.appendChild(musicPathValue);

        QDomElement lrcPath = xml->createElement("lrc_path");
        QDomText lrcPathValue =xml->createTextNode(this->tableWidgePlayListMusic->item(i,3)->text());
        lrcPath.appendChild(lrcPathValue);
        music.appendChild(musicPath);
        music.appendChild(lrcPath);

        musicList.appendChild(music);

    }
    QDomElement movieList = xml->createElement("movie_list");
    movieList.setAttribute("index",this->currentMovieIndex);
    movieList.setAttribute("total",movieNum);
    root.appendChild(movieList);

    for(int i = 0;i < movieNum;i++){
        QDomElement music = xml->createElement("movie");
        QDomElement musicPath = xml->createElement("movie_path");
        QDomText musicPathValue =xml->createTextNode(this->tableWidgePlayListMovie->item(i,2)->text());
        musicPath.appendChild(musicPathValue);

        QDomElement lrcPath = xml->createElement("sutitle_path");
        QDomText lrcPathValue =xml->createTextNode(this->tableWidgePlayListMovie->item(i,3)->text());
        lrcPath.appendChild(lrcPathValue);
        music.appendChild(musicPath);
        music.appendChild(lrcPath);

        movieList.appendChild(music);

    }

    QFile *fileSave =  new QFile("default.list");

    if(!fileSave->open(QIODevice::ReadWrite | QIODevice::Truncate)){
        qDebug()<<"文件打开错误";
    }
    QTextStream out(fileSave);
    qDebug()<<xml->toString();
    xml->save(out,4);
    fileSave->close();

    this->pushButtonAddMovie->setDisabled(false);
    this->pushButtonAddMusic->setDisabled(false);
    this->pushButtonSavePlayList->setDisabled(false);

}
void PlayList::movieClick(const QModelIndex &index)
{
    qDebug()<<"movie click";
}
void PlayList::movieDoubleClick(int row, int column)
{
    qDebug()<<"movie click"<<row<<column<<this->tableWidgePlayListMovie->item(row,2)->text()<<this->tableWidgePlayListMovie->item(row,3)->text();
    emit playMovie(this->tableWidgePlayListMovie->item(row,2)->text(),this->tableWidgePlayListMovie->item(row,3)->text());
}

void PlayList::musicClick(const QModelIndex &index)
{
    qDebug()<<"movie click";
}

void PlayList::musicDoubleClick(int row, int column)
{
    qDebug()<<"music click"<<row<<column<<this->tableWidgePlayListMusic->item(row,2)->text()<<this->tableWidgePlayListMusic->item(row,3)->text();
    this->currentMusicIndex = row;
    qDebug()<<"currentindex --> "<< this->currentMusicIndex;
    emit playMusic(this->tableWidgePlayListMusic->item(row,2)->text(),this->tableWidgePlayListMusic->item(row,3)->text());
}
void PlayList::getplayMode(int mode)
{
    playMode=mode;
  //  emit readyModeMusic();
}

void PlayList::getNextMusic()
{
    qDebug()<<"get Next Music ->"<<playMode;
    QTime time;
    time = QTime::currentTime();
    qsrand(time.msec()+time.second()*1000);

    int index = -1;
    switch(playMode)
    {
    case 0://play one
     //   index = -1;
        break;
    case 1://play ones
        index =this->currentMusicIndex;
        if(back || forward)
        {
            index =this->currentMusicIndex;
            emit playMusic(this->tableWidgePlayListMusic->item(index,2)->text(),this->tableWidgePlayListMusic->item(index,3)->text());
        }
        break;
    case 2://play normal
        index = this->currentMusicIndex+1;
        if(back)
        {
             index -= 2;
             if(index < 0)
                 index = this->tableWidgePlayListMusic->rowCount()-1;
             emit playMusic(this->tableWidgePlayListMusic->item(index,2)->text(),this->tableWidgePlayListMusic->item(index,3)->text());
             this->currentMusicIndex = index;
        }
        if(forward)
        {
            if(index > this->tableWidgePlayListMusic->rowCount()-1)
                index = 0;
             emit playMusic(this->tableWidgePlayListMusic->item(index,2)->text(),this->tableWidgePlayListMusic->item(index,3)->text());
             this->currentMusicIndex = index;
        }
        break;
    case 3://play random
        index = qrand()%( this->tableWidgePlayListMusic->rowCount());
        if(back || forward)
        {
           emit playMusic(this->tableWidgePlayListMusic->item(index,2)->text(),this->tableWidgePlayListMusic->item(index,3)->text());
           this->currentMusicIndex = index;
        }
        break;
    default:
        index = -1;
        break;
    }
   //  this->currentMusicIndex = index;
}
void PlayList::getBackMusic(bool b)// play back
{
    back = !b;
    qDebug()<<"get back music --> "<<back;
}
void PlayList::getForwardMusic(bool f)// play forward
{
    forward = !f;
    qDebug()<<"get forward music --> "<<forward;
}
void PlayList::playNextMusic(int playMode)
{

}
void PlayList::playNextMovie(int playMode)
{

}
bool PlayList::loadPlayList(QString fileName)
{
    QFile file(fileName);
    QString errStr;
    int errLine, errCol;
    //return false;
    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug()<<"XML can find";
        QMessageBox::critical(NULL,"error", "can find default list", QMessageBox::Yes, QMessageBox::Yes);
        //goto ask for new config file,other exit
        return false;

    }
    QDomDocument xml;
    if(!xml.setContent(&file,false, &errStr, &errLine, &errCol))
    {
        qDebug()<<"xml parse error";
        QMessageBox::critical(NULL,"error", "xml parse error", QMessageBox::Yes, QMessageBox::Yes);
        //goto ask for new config file,other exit
        return false;
    }
    QDomElement root = xml.documentElement();
    qDebug()<<root.tagName();
    QDomElement musicList = root.firstChildElement();
    QDomElement music = musicList.firstChildElement();
    QDomNodeList musics = musicList.childNodes();
    qDebug()<<"music num->"<<musics.count();



    //
    QDomElement movieList = musicList.nextSiblingElement();
    QDomElement movie = movieList.firstChildElement();
    QDomNodeList movies = movieList.childNodes();
    qDebug()<<"movie num->"<<movies.count();
    this->tableWidgePlayListMovie->setRowCount(movies.count());
    qDebug()<<"music list attr index - total -> "<<movieList.attributeNode("index").nodeValue()<<movieList.attributeNode("total").nodeValue();
    //check music total
    qDebug()<<"music list attr index -total -> "<<musicList.attributeNode("index").nodeValue()<<musicList.attributeNode("total").nodeValue();
    if(musicList.attributeNode("total").nodeValue().toInt() != musics.count())
    {
        qDebug()<<"music list num parse error";
        return false;
    }
    this->tableWidgePlayListMusic->setRowCount(musics.count());
    this->currentMusicIndex = musicList.attributeNode("index").nodeValue().toInt();
    //check movie total
    if(movieList.attributeNode("total").nodeValue().toInt() !=movies.count())
    {
        qDebug()<<"movie list num parse error";
        return false;
    }
    this->currentMovieIndex = movieList.attributeNode("index").nodeValue().toInt();

    int row = 0;
    while(!music.isNull()){
        //brand << music.attributeNode("brandName").nodeValue();
        QDomElement path = music.firstChildElement();
        QString xmlPath;
        QTableWidgetItem *lrcIcon = new QTableWidgetItem();//
        QTableWidgetItem *lrcAbsPath = new QTableWidgetItem();//
        QTableWidgetItem *musicName = new QTableWidgetItem();
        QTableWidgetItem *musicAbsPath = new QTableWidgetItem();

        while(!path.isNull())
        {
            xmlPath = path.text();
            //qDebug()<<xmlPath;
            QFileInfo fileInfo(xmlPath);
            if(xmlPath.endsWith("mp3",Qt::CaseInsensitive))
            {
                musicAbsPath->setText(xmlPath);
                musicName->setText(fileInfo.baseName());
                lrcIcon->setText("MP3");
                qDebug()<<"MP3"<<xmlPath;
            }
            else if(xmlPath.endsWith("wma",Qt::CaseInsensitive))
            {
                musicAbsPath->setText(xmlPath);
                musicName->setText(fileInfo.baseName());
                lrcIcon->setText("WMA");
                qDebug()<<"WMA"<<xmlPath;

            }
            else if(xmlPath.endsWith("lrc",Qt::CaseInsensitive))
            {
                QFileInfo lrcInfo(xmlPath);
                if(lrcInfo.exists())
                {
                    lrcAbsPath->setText(xmlPath);
                    lrcIcon->setBackground(QBrush(QColor(Qt::green),Qt::SolidPattern));
                }
                else
                {
                    lrcIcon->setBackground(QBrush(QColor(Qt::red),Qt::SolidPattern));
                    lrcAbsPath->setText("");
                }

                qDebug()<<"LRC"<<xmlPath;
            }
            else
            {
                lrcIcon->setBackground(QBrush(QColor(Qt::red),Qt::SolidPattern));
                qDebug()<<"NULL"<<xmlPath;
            }

            path = path.nextSiblingElement();
            //
        }


        this->tableWidgePlayListMusic->setItem(row,0,lrcIcon);
        this->tableWidgePlayListMusic->setItem(row,1,musicName);
        this->tableWidgePlayListMusic->setItem(row,2,musicAbsPath);
        this->tableWidgePlayListMusic->setItem(row,3,lrcAbsPath);
        row++;
        //qDebug()<<"row index"<<row;
        music = music.nextSiblingElement();
    }

/*
    QDomElement movieList = musicList.nextSiblingElement();
    QDomElement movie = movieList.firstChildElement();
    QDomNodeList movies = movieList.childNodes();
    qDebug()<<"movie num->"<<movies.count();
    this->tableWidgePlayListMovie->setRowCount(movies.count());
*/
    row = 0;
    while(!movie.isNull()){
        //brand << music.attributeNode("brandName").nodeValue();
        QDomElement path = movie.firstChildElement();
        QString xmlPath;
        QTableWidgetItem *lrcIcon = new QTableWidgetItem();
        QTableWidgetItem *lrcAbsPath = new QTableWidgetItem();
        QTableWidgetItem *musicName = new QTableWidgetItem();
        QTableWidgetItem *musicAbsPath = new QTableWidgetItem();

        while(!path.isNull())
        {
            xmlPath = path.text();
            //qDebug()<<xmlPath;
            QFileInfo fileInfo(xmlPath);
            if(xmlPath.endsWith("mp4",Qt::CaseInsensitive))
            {
                musicAbsPath->setText(xmlPath);
                musicName->setText(fileInfo.baseName());
                lrcIcon->setText("MP4");
                qDebug()<<"MP4"<<xmlPath;
            }
            else if(xmlPath.endsWith("rmvb",Qt::CaseInsensitive))
            {
                musicAbsPath->setText(xmlPath);
                musicName->setText(fileInfo.baseName());
                lrcIcon->setText("RMVB");
                qDebug()<<"RMVB"<<xmlPath;

            }
            else if(xmlPath.endsWith("flv",Qt::CaseInsensitive))
            {
                musicAbsPath->setText(xmlPath);
                musicName->setText(fileInfo.baseName());
                lrcIcon->setText("FLV");
                qDebug()<<"FLV"<<xmlPath;

            }
            else if(xmlPath.endsWith("avi",Qt::CaseInsensitive))
            {
                musicAbsPath->setText(xmlPath);
                musicName->setText(fileInfo.baseName());
                lrcIcon->setText("AVI");
                qDebug()<<"AVI"<<xmlPath;
            }
            else if(xmlPath.endsWith("sub",Qt::CaseInsensitive))
            {
                QFileInfo lrcInfo(xmlPath);
                if(lrcInfo.exists())
                {
                    lrcAbsPath->setText(xmlPath);
                    lrcIcon->setBackground(QBrush(QColor(Qt::green),Qt::SolidPattern));
                }
                else
                {
                    lrcIcon->setBackground(QBrush(QColor(Qt::red),Qt::SolidPattern));
                    lrcAbsPath->setText("");
                }

                qDebug()<<"SUB"<<xmlPath;
            }
            else
            {
                lrcIcon->setBackground(QBrush(QColor(Qt::red),Qt::SolidPattern));
                qDebug()<<"NULL"<<xmlPath;
            }

            path = path.nextSiblingElement();
            //
        }


        this->tableWidgePlayListMovie->setItem(row,0,lrcIcon);
        this->tableWidgePlayListMovie->setItem(row,1,musicName);
        this->tableWidgePlayListMovie->setItem(row,2,musicAbsPath);
        this->tableWidgePlayListMovie->setItem(row,3,lrcAbsPath);
        row++;
        //qDebug()<<"row index"<<row;
        movie = movie.nextSiblingElement();
    }
    qDebug()<<"parse over";

}
