#include<string>
#include "XLibrary11.hpp"
#include<time.h>
using namespace std;
using namespace XLibrary11;

//�@��ʂ̎��
enum Mode
{
	Title,
	Game,
	Game2,
	Game3,
	ruru,
	ruru2,
};

int main()
{
	int a = 0;
	int t = 0;
	int t2 = 0;
	const int blockNumber = 10;				//�@�u���b�N�̐�
	const int enemyNumber = 20;				//�@��Q���̐�
	const int enemy2Number = 20;		
	int life = 1;
	int life2 = 1;
	int blockInterval = 400.0;				//�@�u���b�N�̊Ԋu
	int enemyInterval = 800.0;				//�@��Q���̊Ԋu
	const float blockAmplitude = 170.0;		//�@�u���b�N�̌���
	const float enemyAmplitude = 200.0;		//	��Q���̌���
	int score = 0;							//  ����������
	float speed = 2.0;						//�@�u���b�N�̐i�ޑ���
	float speed2 = 1.0;						//  ��Q���̐i�ޑ���
	const float gravityspeed = 0.65;		//�@�����鑬��
	const float gravityspeed2 = 0.65;
	const float jumpspeed = 7.0;			//�@�W�����v��
	const float jumpspeed2 = 7.0;
	int k = 3;								//	�����ƌ����̏��
	float gravity = 0.0;					//�@�d��
	float gravity2 = 0.0;
	float blockPosition = 0.0;				//  ��ʁiTitle�͏����̉�ʁj
	float enemyPosition = 0.0;				//
	float enemy2Position = 250.0;			//
	float distance = 0.0;					//  �i�񂾋���
	float distance2 = 0.0;


	Mode mode = Title;
	Float2 blockOffset[blockNumber];
	Float2 enemyOffset[enemyNumber];

	Sprite kasoku1(L"�����o�[.png");		//�����o�[�̉摜
	kasoku1.scale = 4.0;

	Sprite kasoku2(L"�����o�[.png");		//�����o�[�̉摜
	kasoku2.scale = 4.0;
	kasoku2.scale.y = 4.4;

	Sprite kasoku3(L"�����o�[.png");		//�����o�[�̉摜
	kasoku3.scale = 4.0;
	kasoku3.scale.y = 4.8;

	Sprite kasoku4(L"�����o�[.png");		//�����o�[�̉摜
	kasoku4.scale = 4.0;
	kasoku4.scale.y = 5.2;

	Sprite kasoku5(L"�����o�[.png");		//�����o�[�̉摜
	kasoku5.scale = 4.0;
	kasoku5.scale.y = 5.6;

	Sprite kasoku6(L"�����o�[.png");		//�����o�[�̉摜
	kasoku6.scale = 4.0;
	kasoku6.scale.y = 6.0;

	Sprite kasoku7(L"�����o�[.png");		//�����o�[�̉摜
	kasoku7.scale = 4.0;
	kasoku7.scale.y = 6.4;

	Sprite sprite2(L"player.png");		//�@�v���C���[�̉摜
	

	Sprite sprite(L"player2.png");			//�@�v���C���[�̉摜
	sprite2.scale = 1.5;
	sprite.scale = 1.5;

	Sprite block(L"block.png");				//�@�u���b�N�̉摜
	block.scale = 4.0;

	Sprite enemy(L"��Q��.png");			//��Q���̉摜
	enemy.scale = 2.0;

	Sprite enemy2(L"��Q��.png");			//��Q���̉摜
	enemy2.scale = 3.0;

	Text scoreText(L"0", 10.0);
	scoreText.position.y = 200.0;
	scoreText.scale = 10.0;
	scoreText.color = Float4(1.0, 0.0, 0.0, 1.0);

	Text lifeText(L"0", 10.0);
	lifeText.position.y = 180.0;
	lifeText.position.x = -60;
	lifeText.scale = 10.0;
	lifeText.color = Float4(0.0, 0.0, 0.0, 1.0);

	Text life2Text(L"0", 10.0);
	life2Text.position.y = 180.0;
	life2Text.position.x = -180.0;
	life2Text.scale = 10.0;
	life2Text.color = Float4(0.0, 0.0, 0.0, 1.0);

	Text titleText(L"������", 80.0);
	titleText.position.x = 0.0;
	titleText.position.y = 110.0;
	titleText.color = Float4(1.0, 0.0, 0.0, 1.0);
	Camera camera;

	App::SetTitle(L"������");

	Text maltiText(L" �� �}���` ���[�h", 50.0);
	maltiText.position.x = 17.0;
	maltiText.position.y = 20.0;
	maltiText.color = Float4(1.0, 0.0, 0.0, 1.0);

	Text normalText(L"�� NORMAL ���[�h", 50.0);
	normalText.position.x = 30.0;
	normalText.position.y = -50.0;
	normalText.color = Float4(1.0, 0.0, 0.0, 1.0);

	Text hardText(L"��  HARD  ���[�h", 50.0);
	hardText.position.x = 30.0;
	hardText.position.y = -120.0;
	hardText.color = Float4(1.0, 0.0, 0.0, 1.0);

	Text rurugoText(L" �X�y�[�X�@�����т��� ", 50.0);
	rurugoText.position.x = 30.0;
	rurugoText.position.y = -190.0;
	rurugoText.color = Float4(1.0, 0.0, 0.0, 1.0);

	Text ruru01Text(L"������@", 70.0);
	ruru01Text.position.x = 10.0;
	ruru01Text.position.y = 200.0;
	ruru01Text.color = Float4(1.0, 0.0, 0.0, 1.0);

	Text ruru02Text(L"�X�y�[�X�L�[�@�W�����v", 20.0);
	ruru02Text.position.x = 10.0;
	ruru02Text.position.y = 100.0;
	ruru02Text.color = Float4(0.0, 0.0, 0.0, 1.0);

	Text ruru03Text(L"���@�����@�@�@���@����", 20.0);
	ruru03Text.position.x = 10.0;
	ruru03Text.position.y = 60.0;
	ruru03Text.color = Float4(0.0, 0.0, 0.0, 1.0);

	Text ruru04Text(L"���@�ő�܂ŉ���", 20.0);
	ruru04Text.position.x = 10.0;
	ruru04Text.position.y = 20.0;
	ruru04Text.color = Float4(0.0, 0.0, 0.0, 1.0);

	Text ruru05Text(L"���Ł@�ő�܂Ō���", 20.0);
	ruru05Text.position.x = 10.0;
	ruru05Text.position.y = -20.0;
	ruru05Text.color = Float4(0.0, 0.0, 0.0, 1.0);

	Text ruru0Text(L"���[������", 70.0);
	ruru0Text.position.x = 10.0;
	ruru0Text.position.y = 200.0;
	ruru0Text.color = Float4(1.0, 0.0, 0.0, 1.0);

	Text ruruText(L"1 �u���b�N�̊Ԃ𔲂��ē��_���҂���!!", 20.0);
	ruruText.position.x = 10.0;
	ruruText.position.y = 100.0;
	ruruText.color = Float4(0.0, 0.0, 0.0, 1.0);

	Text ruru2Text(L"2 �u���b�N�ɓ�����ƃQ�[���I�[�o�[", 20.0);
	ruru2Text.position.x = 5.0;
	ruru2Text.position.y = 60.0;
	ruru2Text.color = Float4(0.0, 0.0, 0.0, 1.0);

	Text ruru3Text(L"3 �@HARD�@���[�h�́@�@�@�����킻��", 20.0);
	ruru3Text.position.x = 10.0;
	ruru3Text.position.y = 20.0;
	ruru3Text.color = Float4(0.0, 0.0, 0.0, 1.0);

	Text ruru4Text(L"SPACE�L�[�Ł@�^�C�g���@��", 20.0);
	ruru4Text.position.x = -20.0;
	ruru4Text.position.y = -120.0;
	ruru4Text.color = Float4(1.0, 0.0, 0.0, 1.0);

	Text ruru06Text(L"�@���@�Ł@���̃y�[�W�@�� ", 20.0);
	ruru06Text.position.x = -20.0;
	ruru06Text.position.y = -200.0;
	ruru06Text.color = Float4(1.0, 0.0, 0.0, 1.0);

	Text ruru07Text(L"�@���@�Ł@�O�̃y�[�W�@�� ", 20.0);
	ruru07Text.position.x = -20.0;
	ruru07Text.position.y = -160.0;
	ruru07Text.color = Float4(1.0, 0.0, 0.0, 1.0);

	Text ruru08Text(L"���΂炭���҂���������", 50.0);
	ruru08Text.position.x = 10.0;
	ruru08Text.position.y = 0.0;
	ruru08Text.color = Float4(1.0, 0.0, 0.0, 1.0);
	

	Sound flySound(L"fly.wav");			//�W�����v�̉�
	Sound hitSound(L"hit.wav");			//��Q���ɓ���������
	Sound pointSound(L"point.wav");		//�X�R�A�����Z���ꂽ���̉�


	//�@�J��Ԃ�
	while (App::Refresh())
	{
		camera.Update();

		switch (mode)
		{
			//�^�C�g����ʂ̏���
		case Title:

			//�X�y�[�X���������烋�[��������
			if (App::GetKeyDown(VK_SPACE))
			{
				k = 3;
				blockPosition = 0.0;
				speed = 2.0;
				blockInterval = 400.0;
				gravity = 0.0;
				distance = sprite.position.x;
				score = 0;
				mode = ruru;
			}

			//�\���L�[�̍�����������Q�[�����(�m�[�}��)��
			if (App::GetKeyDown(VK_LEFT))
			{
				//�p�����[�^�[�����Z�b�g
				k = 3;
				blockPosition = 0.0;
				speed = 2.0;
				blockInterval = 400.0;
				gravity = 0.0;
				distance = sprite.position.x;
				score = 0;
				/*
				�u���b�N����ׂ鏈��
				*/

				for (int i = 0; i < blockNumber; i++)
				{
					//�u���b�N�����ɓ��Ԋu�A�c�Ƀ����_���ɕ��ׂ�
					blockOffset[i] = Float2(
						blockPosition + blockInterval,
						rand() / (float)RAND_MAX * blockAmplitude - blockAmplitude / 2
					);
					blockPosition = blockOffset[i].x;
				}
				mode = Game;
			}

			//�\�����[�́�����������Q�[����ʁi�}���`�j��
			if (App::GetKeyDown(VK_UP))
			{
				sprite2.position = Float3(-280.0, 0.0, 0.0);
				//�p�����[�^�[�����Z�b�g
				sprite2.scale = 1.5;
				sprite.scale = 1.5;
				a == 0;
				k = 3;
				blockPosition = 0.0;
				enemyPosition = 0.0;
				enemy2Position = 250.0;
				speed = 4.0;
				speed2 = 2.0;
				blockInterval = 400.0;
				gravity = 0.0;
				gravity2 = 0.0;
				distance = sprite.position.x;
				distance2 = sprite2.position.x;
				score = 0;
				life = 3;
				life2 = 3;
				lifeText.color = Float4(0.0, 0.0, 0.0, 1.0);
				life2Text.color = Float4(0.0, 0.0, 0.0, 1.0);
 				
				//�u���b�N����ׂ鏈��
				

				for (int i = 0; i < blockNumber; i++)
				{
					//�u���b�N�����ɓ��Ԋu�A�c�Ƀ����_���ɕ��ׂ�
					blockOffset[i] = Float2(
						blockPosition + blockInterval,
						rand() / (float)RAND_MAX * blockAmplitude - blockAmplitude / 2
					);
					blockPosition = blockOffset[i].x;
				}

				for (int i = 0; i < enemyNumber; i++)
				{
					//��Q�������ɓ��Ԋu�A�c�Ƀ����_���ɕ��ׂ�
					enemyOffset[i] = Float2(
						enemyPosition + enemyInterval,
						rand() / (float)RAND_MAX * enemyAmplitude - enemyAmplitude / 2
					);
					enemyPosition = enemyOffset[i].x;
				}
				mode = Game3;
			}

			//�\�����[�݂̂�����������Q�[����ʁi�n�[�h�j��
			if (App::GetKeyDown(VK_RIGHT))
			{
				//�p�����[�^�[�����Z�b�g
				k = 3;
				blockPosition = 0.0;
				enemyPosition = 0.0;
				enemy2Position = 250.0;
				speed = 2.0;
				speed2 = 1.0;
				blockInterval = 400.0;
				gravity = 0.0;
				distance = sprite.position.x;
				score = 0;
				/*
				�u���b�N����ׂ鏈��
				*/

				for (int i = 0; i < blockNumber; i++)
				{
					//�u���b�N�����ɓ��Ԋu�A�c�Ƀ����_���ɕ��ׂ�
					blockOffset[i] = Float2(
						blockPosition + blockInterval,
						rand() / (float)RAND_MAX * blockAmplitude - blockAmplitude / 2
					);
					blockPosition = blockOffset[i].x;
				}

				for (int i = 0; i < enemyNumber; i++)
				{
					//��Q�������ɓ��Ԋu�A�c�Ƀ����_���ɕ��ׂ�
					enemyOffset[i] = Float2(
						enemyPosition + enemyInterval,
						rand() / (float)RAND_MAX * enemyAmplitude - enemyAmplitude / 2
					);
					enemyPosition = enemyOffset[i].x;
				}
				mode = Game2;
			}




			//�v���C���[�����Z�b�g
			sprite.position = Float3(-200.0, 0.0, 0.0);
			sprite.angles.z = 0.0;
			sprite.Draw();

			titleText.Draw();
			scoreText.Draw();
			normalText.Draw();
			hardText.Draw();
			rurugoText.Draw();
			maltiText.Draw();

			break;


		case ruru:
			k = 3;
			blockPosition = 0.0;
			enemyPosition = 0.0;
			speed = 2.0;
			speed2 = 1.0;
			blockInterval = 400.0;
			gravity = 0.0;
			gravity2 = 0.0;
			distance = sprite.position.x;
			score = 0;
			ruru01Text.Draw();
			ruru02Text.Draw();
			ruru03Text.Draw();
			ruru04Text.Draw();
			ruru05Text.Draw();
			ruru4Text.Draw();
			ruru06Text.Draw();

			if (App::GetKeyDown(VK_SPACE))
			{
				mode = Title;
			}


			if (App::GetKeyDown(VK_RIGHT))
			{
				k = 3;
				blockPosition = 0.0;
				enemyPosition = 0.0;
				enemy2Position = 250.0;
				speed = 2.0;
				speed2 = 1.0;
				blockInterval = 400.0;
				gravity = 0.0;
				distance = sprite.position.x;
				score = 0;
				mode = ruru2;
			}

			break;
			//�@���[������2�y�[�W��
		case ruru2:
	
			k = 3;
			blockPosition = 0.0;
			enemyPosition = 0.0;
			speed = 2.0;
			speed2 = 1.0;
			blockInterval = 400.0;
			gravity = 0.0;
			gravity2 = 0.0;
			distance = sprite.position.x;
			score = 0;
			enemy2.position.x = 50.0;
			enemy2.position.y = 20;
			enemy2.Draw();
			ruru0Text.Draw();
			ruruText.Draw();
			ruru2Text.Draw();
			ruru3Text.Draw();
			ruru4Text.Draw();
			ruru07Text.Draw();

			if (App::GetKeyDown(VK_SPACE))
			{
				mode = Title;
			}


			if (App::GetKeyDown(VK_LEFT))
			{
				k = 3;
				blockPosition = 0.0;
				enemyPosition = 0.0;
				enemy2Position = 250.0;
				speed = 2.0;
				speed2 = 1.0;
				blockInterval = 400.0;
				gravity = 0.0;
				gravity2 = 0.0;
				distance = sprite.position.x;
				score = 0;
				mode = ruru;
			}
			break;




			//�Q�[����ʁi�}���`�j�̏���
		case Game3:
			clock_t start, end;
			
			//�����G�t�F�N�g�̏ꏊ
			kasoku1.position.x = 100;
			kasoku1.position.y = 160;
			kasoku1.Draw();

			kasoku2.position.x = 115;
			kasoku2.position.y = 163;

			kasoku3.position.x = 130;
			kasoku3.position.y = 166;

			kasoku4.position.x = 145;
			kasoku4.position.y = 169;

			kasoku5.position.x = 160;
			kasoku5.position.y = 172;

			kasoku6.position.x = 175;
			kasoku6.position.y = 175;

			kasoku7.position.x = 190;
			kasoku7.position.y = 178;


			if (t < 42)
			{
				t++;
			}
			if (t2 < 42)
			{
				t2++;
			}

			//���C�t�̊Ǘ�

			//��ʊO�ɍs���Ǝ���
			if (life > 0)
			{
				if (sprite.position.y <= -App::GetWindowSize().y)
				{
					if (life > 1)
					{
						t = 0;
						sprite.position.y = 80.0;
					}
					gravity = 0.0;
					life -= 1;
					hitSound.Play();
				}
			}
			if (life2 > 0)
			{
				if (sprite2.position.y <= -App::GetWindowSize().y)
				{
					if (life2 > 1)
					{
						t2 = 0;
						sprite2.position.y = 80.0;
					}
					gravity2 = 0.0;
					life2 -= 1;
					hitSound.Play();
				}
			}
			
			//2�L�����̃��C�t��0�ɂȂ������Ƀ^�C�g����ʂ�
			if (life <= 0 && life2 <= 0)
			{
				speed = 2.0;
				mode = Title;
			}
			

			for (int i = 0; i < blockNumber; i++)
			{
				

				// �u���b�N�����ɍs���Č����Ȃ��Ȃ�����A�E�Ɉړ�����
				if (blockOffset[i].x < -App::GetWindowSize().x)
				{
					blockOffset[i] = Float2(
						blockPosition + blockInterval,
						rand() / (float)RAND_MAX * blockAmplitude - blockAmplitude / 2
					);
					blockPosition = blockOffset[i].x;
				}


				float playerSize = sprite.GetSize().x * sprite.scale.x * 0.8;
				float blockwidth = (block.GetSize().x * block.scale.x + playerSize) / 2.0;
				float blockHeaght = (blockAmplitude - playerSize) / 2.0;

				//�@�����蔻��
				if (blockOffset[i].x - blockwidth < sprite.position.x &&
					blockOffset[i].x + blockwidth > sprite.position.x)
				{
					if (blockOffset[i].y - blockHeaght > sprite.position.y ||
						blockOffset[i].y + blockwidth < sprite.position.y)

					{
						//�@�����������̏���
						if (life > 0 && 40 < t)
						{
							if (life > 1)
							{
								t = 0;
							}
							gravity = 0.0;
							hitSound.Play();
							life -= 1;
						}

					}

				}

				if (blockOffset[i].x - blockwidth < sprite2.position.x &&
					blockOffset[i].x + blockwidth > sprite2.position.x)
				{
					if (blockOffset[i].y - blockHeaght > sprite2.position.y ||
						blockOffset[i].y + blockwidth < sprite2.position.y)

					{
						//�@�����������̏���
						if (life2 > 0 && 40 < t2)
						{
							if (life2 > 1)
							{
								t2 = 0;
							}
							gravity2 = 0.0;
							hitSound.Play();
							life2 -= 1;
						}
					}

				}

				//�@�u���b�N�𓮂�������
				blockOffset[i].x -= speed;
				//�@�㑤�̃u���b�N��`�悷�鏈��
				block.position = blockOffset[i];
				block.position.y += (block.GetSize().y * block.scale.y + blockAmplitude) / 2.0;
				block.Draw();

				//�@�����̃u���b�N��`�悷�鏈��
				block.position = blockOffset[i];
				block.position.y -= (block.GetSize().y * block.scale.y + blockAmplitude) / 2.0;
				block.Draw();
			}

			for (int i = 0; i < enemyNumber; i++)
			{
				// ��Q�������ɍs���Č����Ȃ��Ȃ�����A�E�Ɉړ�����
				if (enemyOffset[i].x < -App::GetWindowSize().x)
				{
					enemyOffset[i] = Float2(
						enemyPosition + enemyInterval,
						rand() / (float)RAND_MAX * enemyAmplitude - enemyAmplitude / 2
					);
					enemyPosition = enemyOffset[i].x;
				}

				float playerSize = sprite.GetSize().x * sprite.scale.x * 0.8;
				float enemywidth = (enemy.GetSize().x * enemy.scale.x + playerSize) / 2.0;
				float enemyHeaght = (enemyAmplitude - playerSize) / 2.0;

				//�@�����蔻��
				if (enemyOffset[i].x - enemywidth < sprite.position.x &&
					enemyOffset[i].x + enemywidth > sprite.position.x)
				{
					if (enemyOffset[i].y - enemyHeaght - 50 < sprite.position.y &&
						enemyOffset[i].y - enemyHeaght > sprite.position.y)

					{
						//�@�����������̏���
						if (life > 0 && 40 < t)
						{
							if (life > 1)
							{
								t = 0;
							}
							gravity = 0.0;
							hitSound.Play();
							life -= 1;
						}

					}
					if (enemyOffset[i].y + enemyHeaght + 50 > sprite.position.y &&
						enemyOffset[i].y + enemyHeaght < sprite.position.y)

					{
						//�@�����������̏���
						if (life > 0 && t > 40)
						{
							if (life > 1)
							{
								t = 0;
							}
							gravity = 0.0;
							hitSound.Play();
							life -= 1;
						}

					}
				}

				if (enemyOffset[i].x - enemywidth < sprite2.position.x &&
					enemyOffset[i].x + enemywidth > sprite2.position.x)
				{
					if (enemyOffset[i].y - enemyHeaght - 50 < sprite2.position.y &&
						enemyOffset[i].y - enemyHeaght > sprite2.position.y)

					{
						//�@�����������̏���
						if (life2 > 0 && 40 < t2)
						{
							if (life2 > 1)
							{
								t2 = 0;
							}
							gravity2 = 0.0;
							hitSound.Play();
							life2 -= 1;
						}

					}
					if (enemyOffset[i].y + enemyHeaght + 50 > sprite2.position.y &&
						enemyOffset[i].y + enemyHeaght < sprite2.position.y)

					{
						//�@�����������̏���
						if (life2 > 0 && 40 < t2)
						{
							if (life2 > 1)
							{
								t2 = 0;
							}
							gravity2 = 0.0;
							hitSound.Play();
							life2 -= 1;
						}

					}
				}

				

				//�@��Q���𓮂�������
				enemyOffset[i].x -= speed2;

				enemy.position = enemyOffset[i];
				enemy.position.y += (enemy.GetSize().y * enemy.scale.y + enemyAmplitude) / 2.0;
				enemy.Draw();

				//�@�����̏�Q����`�悷�鏈��
				enemy.position = enemyOffset[i];
				enemy.position.y -= (enemy.GetSize().y * enemy.scale.y + enemyAmplitude) / 2.0;
				enemy.Draw();

			}


			blockPosition -= speed;
			enemyPosition -= speed;

			//�@�W�����v�̏���
			if (App::GetKeyDown(VK_SPACE) && life > 0)
			{
				flySound.Play();
				gravity = jumpspeed;
			}

			if (App::GetKeyDown(VK_RETURN) && life2 > 0)
			{
				flySound.Play();
				gravity2 = jumpspeed2;
			}
			

			//�@�d�͂̏���
			gravity -= gravityspeed;
			gravity2 -= gravityspeed2;
			sprite.position.y += gravity;
			sprite.angles.z = gravity * 5.0; 
			sprite2.position.y += gravity2;
			sprite2.angles.z = gravity2 * 5.0;

											   //�@�v���C���[�̕`��
			sprite.Draw();
			sprite2.Draw();

			//���������Z
			distance += speed; 

			if (distance > blockInterval)
			{
				distance -= blockInterval;
				score++;
				
				// 75�|�C���g�܂łP�|�C���g���Ƃɏ������������鏈��
				if (76.0 > score)
				{
						speed += 0.15;
						if (score % 3 == 0)
						{
							speed2 += 0.45;
						}
				}
				pointSound.Play();

			}

			lifeText.Create(to_wstring(life), 10.0);
			lifeText.Draw();
			if (life == 0)
			{
				lifeText.color = Float4(1.0, 0.0, 0.0, 1.0);
			}

			life2Text.Create(to_wstring(life2), 10.0);
			life2Text.Draw();
			if (life2 == 0)
			{
				life2Text.color = Float4(1.0, 0.0, 0.0, 1.0);
			}

			//�����G�t�F�N�g�̏���
			if (k >= 0)
			{
				kasoku1.Draw();
			}

			if (k >= 1)
			{
				kasoku2.Draw();
			}

			if (k >= 2)
			{
				kasoku3.Draw();
			}

			if (k >= 3)
			{
				kasoku4.Draw();
			}

			if (k >= 4)
			{
				kasoku5.Draw();
			}

			if (k >= 5)
			{
				kasoku6.Draw();
			}

			if (k >= 6)
			{
				kasoku7.Draw();
			}

			//�ő�����̏���
			if (App::GetKeyDown(VK_UP)||
				App::GetKeyDown('W'))
			{
				if (k == 0)
				{
					speed += 3.0;
					k += 6;
				}

				if (k == 1)
				{
					speed += 2.5;
					k += 5;
				}

				if (k == 2)
				{
					speed += 2.0;
					k += 4;
				}

				if (k == 3)
				{
					speed += 1.5;
					k += 3;
				}

				if (k == 4)
				{
					speed += 1.0;
					k += 2;
				}

				if (k == 5)
				{
					speed += 0.5;
					k += 1;
				}

			}

			//�ő匸���̏���

			if (App::GetKeyDown(VK_DOWN) ||
				App::GetKeyDown('S'))
			{
				if (k == 1)
				{
					speed -= 0.5;
					k -= 1;
				}
				if (k == 2)
				{
					speed -= 1.0;
					k -= 2;
				}

				if (k == 3)
				{
					speed -= 1.5;
					k -= 3;
				}

				if (k == 4)
				{
					speed -= 2.0;
					k -= 4;
				}
				if (k == 5)
				{
					speed -= 2.5;
					k -= 5;
				}

				if (k == 6)
				{
					speed -= 3.0;
					k -= 6;
				}
			}

			//�E�ŉ���
			if (App::GetKeyDown(VK_RIGHT) ||
				App::GetKeyDown('D'))
			{
				if (k < 6)
				{
					speed += 0.5;
					k = k + 1;
				}
			}

			//���Ō���

			if (App::GetKeyDown(VK_LEFT) ||
				App::GetKeyDown('A'))
			{
				if (k > 0)
				{
					speed -= 0.5;
					k = k - 1;
				}
			}

			if (App::GetKeyDown('9') && a == 0
				&& speed2 < 100)
			{
				a += 1;
				speed2 += 100;
				speed += 40;
				sprite2.scale = 10;
				sprite.scale = 10;
				life += 100;
				life2 += 100;
			}

			if (speed2 > 100)
			{
				ruru08Text.Draw();
			}

			break;

			//�Q�[����ʁi�n�[�h�j�̏���
		case Game2:

			for (int i = 0; i < blockNumber; i++)
			{
				// �u���b�N�����ɍs���Č����Ȃ��Ȃ�����A�E�Ɉړ�����
				if (blockOffset[i].x < -App::GetWindowSize().x)
				{
					blockOffset[i] = Float2(
						blockPosition + blockInterval,
						rand() / (float)RAND_MAX * blockAmplitude - blockAmplitude / 2
					);
					blockPosition = blockOffset[i].x;
				}


				float playerSize = sprite.GetSize().x * sprite.scale.x * 0.8;
				float blockwidth = (block.GetSize().x * block.scale.x + playerSize) / 2.0;
				float blockHeaght = (blockAmplitude - playerSize) / 2.0;

				//�@�����蔻��
				if (blockOffset[i].x - blockwidth < sprite.position.x &&
					blockOffset[i].x + blockwidth > sprite.position.x)
				{
					if (blockOffset[i].y - blockHeaght > sprite.position.y ||
						blockOffset[i].y + blockwidth < sprite.position.y)

					{
						//�@�����������̏���
						hitSound.Play();
						speed = 2.0;
						mode = Title;

					}

				}
				//�@�u���b�N�𓮂�������
				blockOffset[i].x -= speed;
				//�@�㑤�̃u���b�N��`�悷�鏈��
				block.position = blockOffset[i];
				block.position.y += (block.GetSize().y * block.scale.y + blockAmplitude) / 2.0;
				block.Draw();

				//�@�����̃u���b�N��`�悷�鏈��
				block.position = blockOffset[i];
				block.position.y -= (block.GetSize().y * block.scale.y + blockAmplitude) / 2.0;
				block.Draw();
			}

			for (int i = 0; i < enemyNumber; i++)
			{
				// ��Q�������ɍs���Č����Ȃ��Ȃ�����A�E�Ɉړ�����
				if (enemyOffset[i].x < -App::GetWindowSize().x)
				{
					enemyOffset[i] = Float2(
						enemyPosition + enemyInterval,
						rand() / (float)RAND_MAX * enemyAmplitude - enemyAmplitude / 2
					);
					enemyPosition = enemyOffset[i].x;
				}

				float playerSize = sprite.GetSize().x * sprite.scale.x * 0.8;
				float enemywidth = (enemy.GetSize().x * enemy.scale.x + playerSize) / 2.0;
				float enemyHeaght = (enemyAmplitude - playerSize) / 2.0;

				//�@�����蔻��
				if (enemyOffset[i].x - enemywidth < sprite.position.x &&
					enemyOffset[i].x + enemywidth > sprite.position.x)
				{
					if (enemyOffset[i].y - enemyHeaght - 50 < sprite.position.y &&
						enemyOffset[i].y - enemyHeaght > sprite.position.y)

					{
						//�@�����������̏���
						hitSound.Play();
						speed = 2.0;
						mode = Title;


					}
					if (enemyOffset[i].y + enemyHeaght + 50 > sprite.position.y &&
						enemyOffset[i].y + enemyHeaght < sprite.position.y)

					{
						//�@�����������̏���
						hitSound.Play();
						speed = 2.0;
						mode = Title;


					}
				}
					//�@��Q���𓮂�������
					enemyOffset[i].x -= speed2;

					enemy.position = enemyOffset[i];
					enemy.position.y += (enemy.GetSize().y * enemy.scale.y + enemyAmplitude) / 2.0;
					enemy.Draw();

					//�@�����̏�Q����`�悷�鏈��
					enemy.position = enemyOffset[i];
					enemy.position.y -= (enemy.GetSize().y * enemy.scale.y + enemyAmplitude) / 2.0;
					enemy.Draw();
				
			}

			
				blockPosition -= speed;
				enemyPosition -= speed;

				//�@�W�����v�̏���
				if (App::GetKeyDown(VK_SPACE))
				{
					flySound.Play();
					gravity = jumpspeed;
				}

				//�@�d�͂̏���
				gravity -= gravityspeed;
				sprite.position.y += gravity;
				sprite.angles.z = gravity * 5.0;  

				//�@�v���C���[�̕`��
				sprite.Draw();

				//���������Z
				distance += speed;

				if (distance > blockInterval)
				{
					distance -= blockInterval;
					score++;

					//75�|�C���g�܂łP�|�C���g���Ƃɏ������������鏈��
					if (76.0 > score)
					{
						speed += 0.15;
					}

					if (score % 3 == 0)
					{
						if (76.0 > score)
						{
							speed2 += 0.45;
						}
					}
				}

				scoreText.Create(to_wstring(score), 10.0);
				scoreText.Draw();

				//�ő�����̏���

				if (App::GetKeyDown(VK_UP))
				{
					if (k == 0)
					{
						speed += 3.0;
						k += 6;
					}

					if (k == 1)
					{
						speed += 2.5;
						k += 5;
					}

					if (k == 2)
					{
						speed += 2.0;
						k += 4;
					}

					if (k == 3)
					{
						speed += 1.5;
						k += 3;
					}

					if (k == 4)
					{
						speed += 1.0;
						k += 2;
					}

					if (k == 5)
					{
						speed += 0.5;
						k += 1;
					}
				}

				//�ő匸���̏���

				if (App::GetKeyDown(VK_DOWN))
				{
					if (k == 1)
					{
						speed -= 0.5;
						k -= 1;
					}
					if (k == 2)
					{
						speed -= 1.0;
						k -= 2;
					}

					if (k == 3)
					{
						speed -= 1.5;
						k -= 3;
					}

					if (k == 4)
					{
						speed -= 2.0;
						k -= 4;
					}
					if (k == 5)
					{
						speed -= 2.5;
						k -= 5;
					}

					if (k == 6)
					{
						speed -= 3.0;
						k -= 6;
					}
				}


				//�E�ŉ���
				if (App::GetKeyDown(VK_RIGHT))
				{
					if (k < 6)
					{
						speed += 0.5;
						k = k + 1;

					}
				}


				//���Ō���

				if (App::GetKeyDown(VK_LEFT))

				{
					if (k > 0)
					{
						speed -= 0.5;
						k = k - 1;
					}

				}

			

			break;

			//�Q�[����ʁi�m�[�}���j�̏���
		case Game:

			for (int i = 0; i < blockNumber; i++)
			{
				// �u���b�N�����ɍs���Č����Ȃ��Ȃ�����A�E�Ɉړ�����
				if (blockOffset[i].x < -App::GetWindowSize().x)
				{
					blockOffset[i] = Float2(
						blockPosition + blockInterval,
						rand() / (float)RAND_MAX * blockAmplitude - blockAmplitude / 2
					);
					blockPosition = blockOffset[i].x;
				}


				float playerSize = sprite.GetSize().x * sprite.scale.x * 0.8;
				float blockwidth = (block.GetSize().x * block.scale.x + playerSize) / 2.0;
				float blockHeaght = (blockAmplitude - playerSize) / 2.0;

				//�@�����蔻��
				if (blockOffset[i].x - blockwidth < sprite.position.x &&
					blockOffset[i].x + blockwidth > sprite.position.x)
				{
					if (blockOffset[i].y - blockHeaght > sprite.position.y ||
						blockOffset[i].y + blockwidth < sprite.position.y)

					{
						//�@�����������̏���
						hitSound.Play();
						speed = 2.0;
						mode = Title;

					}

				}
				//�@�u���b�N�𓮂�������
				blockOffset[i].x -= speed;
				//�@�㑤�̃u���b�N��`�悷�鏈��
				block.position = blockOffset[i];
				block.position.y += (block.GetSize().y * block.scale.y + blockAmplitude) / 2.0;
				block.Draw();

				//�@�����̃u���b�N��`�悷�鏈��
				block.position = blockOffset[i];
				block.position.y -= (block.GetSize().y * block.scale.y + blockAmplitude) / 2.0;
				block.Draw();
			}

			blockPosition -= speed;

			//�@�W�����v�̏���
			if (App::GetKeyDown(VK_SPACE))
			{
				flySound.Play();
				gravity = jumpspeed;
			}

			//�@�d�͂̏���
			gravity -= gravityspeed;
			sprite.position.y += gravity;
			sprite.angles.z = gravity * 5.0;   // ���̕ӂ����₵��

											   //�@�v���C���[�̕`��
			sprite.Draw();

			//���������Z
			distance += speed;

			if (distance > blockInterval)
			{
				distance -= blockInterval;
				score++;

				//75�|�C���g�܂łP�|�C���g���Ƃɏ������������鏈��
				if (76.0 > score)
				{
					speed += 0.10;
				}
				pointSound.Play();
			}

			scoreText.Create(to_wstring(score), 10.0);
			scoreText.Draw();

			//�ő�����̏���

			if (App::GetKeyDown(VK_UP))
			{
				if (k == 0)
				{
					speed += 3.0;
					k += 6;
				}

				if (k == 1)
				{
					speed += 2.5;
					k += 5;
				}

				if (k == 2)
				{
					speed += 2.0;
					k += 4;
				}

				if (k == 3)
				{
					speed += 1.5;
					k += 3;
				}

				if (k == 4)
				{
					speed += 1.0;
					k += 2;
				}

				if (k == 5)
				{
					speed += 0.5;
					k += 1;
				}
			}

			//�ő匸���̏���

			if (App::GetKeyDown(VK_DOWN))
			{
				if (k == 1)
				{
					speed -= 0.5;
					k -= 1;
				}
				if (k == 2)
				{
					speed -= 1.0;
					k -= 2;
				}

				if (k == 3)
				{
					speed -= 1.5;
					k -= 3;
				}

				if (k == 4)
				{
					speed -= 2.0;
					k -= 4;
				}
				if (k == 5)
				{
					speed -= 2.5;
					k -= 5;
				}

				if (k == 6)
				{
					speed -= 3.0;
					k -= 6;
				}
			}


			//�E�ŉ���
			if (App::GetKeyDown(VK_RIGHT))
			{
				if (k < 6)
				{
					speed += 0.5;
					k = k + 1;
				}
			}


			//���Ō���

			if (App::GetKeyDown(VK_LEFT))

			{
				if (k > 0)
				{
					speed -= 0.5;
					k = k - 1;
				}

			}

			break;
		}
	}
	return 0;

}

